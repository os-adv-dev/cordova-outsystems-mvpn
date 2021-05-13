var axios;
var base64;
const path = require("path")
const fs = require('fs');
const { log } = require('../common');

const pluginId = "cordova-plugin-mvpn";

module.exports = function(context) {


	if(isCordovaAbove(context,8)){
        axios = require('axios');
        base64 = require('base-64');
	}else{
        base64 = context.requireCordovaModule('base-64');
        axios = context.requireCordovaModule('axios');
	}

	process.chdir(context.opts.projectRoot);

    var mode = "";
	if (context.cmdLine.indexOf('release') >= 0) {
	    mode = 'release';
	}
	mode = 'debug';

    const projectName = getConfigParser(context, path.join(context.opts.projectRoot, 'config.xml')).name();
    const projectNameEncoded = encodeURIComponent(projectName);

    const plugin = JSON.parse(fs.readFileSync(path.join(context.opts.projectRoot,"plugins", 'fetch.json'),"utf8"))[pluginId];

    var encryptedAuth = plugin.variables.CREDENTIALS;
    if(encryptedAuth.includes(":")){
        encryptedAuth = "Basic "+base64.encode(encryptedAuth);
    }
    var baseUrl = plugin.variables.WEBSERVICEURL;

    //let form = new FormData();
    var mdxFile;
    log("File Size:")
    if(fs.existsSync("platforms/android")){
        if(mode == "release"){
            baseUrl += "?type=release&platform=android&name="+projectNameEncoded;
            mdxFile = fs.readFileSync('mdx/android-release.mdx');
            log(fs.statSync('mdx/android-release.mdx').size/ (1024*1024))
        }else{
            baseUrl += "?type=debug&platform=android&name="+projectNameEncoded;
            mdxFile = fs.readFileSync('mdx/android-debug.mdx');
            log(fs.statSync('mdx/android-debug.mdx').size/ (1024*1024))
        }
    }else{
        baseUrl += "?type="+mode+"&platform=ios&name="+projectNameEncoded;
        var files = []
        var forEnd = true;
        files = fs.readdirSync("platforms/ios/build/device");
        files.forEach((file)=>{
            var curSource = path.join("platforms/ios/build/device",file);
            log(file)
            if(path.extname(file) == ".mdx" && forEnd){
                log("1")
                forEnd=false;
                mdxFile = fs.readFileSync(curSource);
                log(fs.statSync(curSource).size/ (1024*1024))
            }
        });
        if(mdxFile == undefined){
            log("2")
            mdxFile = fs.readFileSync(path.join("platforms","ios",projectName+".mdx"));
            log(fs.statSync(path.join("platforms","ios",projectName+".mdx")).size/ (1024*1024))
        }
    }
    axios.post(baseUrl,mdxFile,{
        headers:{
            "Authorization": encryptedAuth
        }
    }).then((response)=>{
        log("Successfully sent file!!");
    }).catch((error)=>{
        log("Failed to send file!!");
        log(error);
    });
}

function isCordovaAbove (context, version) {
	var cordovaVersion = context.opts.cordova.version;
	console.log(cordovaVersion);
	var sp = cordovaVersion.split('.');
	return parseInt(sp[0]) >= version;
}

function getConfigParser(context, config){
    var semver;

    if(isCordovaAbove(context,8)){
        semver = require('semver');
	}else{
        semver = context.requireCordovaModule('semver');
	}

    if(semver.lt(context.opts.cordova.version, '5.4.0')) {
      ConfigParser = context.requireCordovaModule('cordova-lib/src/ConfigParser/ConfigParser');
    } else {
      ConfigParser = context.requireCordovaModule('cordova-common/src/ConfigParser/ConfigParser');
    }
  
    return new ConfigParser(config);
}