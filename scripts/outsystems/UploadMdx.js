var axios;
var base64;
const path = require("path")
const fs = require('fs');
const common = require('../common');
const log = common.log;

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
    var projectName = JSON.parse(fs.readFileSync(common.PackageJson).toString()).displayName;

    const plugin = JSON.parse(fs.readFileSync(path.join(context.opts.projectRoot,"plugins", 'fetch.json'),"utf8"))[common.PluginId];

    var encryptedAuth = plugin.variables.CREDENTIALS;
    if(encryptedAuth.includes(":")){
        encryptedAuth = "Basic "+base64.encode(encryptedAuth);
    }
    var baseUrl = plugin.variables.WEBSERVICEURL;
    
    //let form = new FormData();
    var mdxFile;
    if(fs.existsSync("platforms/android")){
        projectName = encodeURIComponent(projectName)
        if(mode == "release"){
            baseUrl += "?type=release&platform=android&name="+projectName;
            mdxFile = fs.readFileSync('mdx/android-release.mdx');
        }else{
            baseUrl += "?type=debug&platform=android&name="+projectName;
            mdxFile = fs.readFileSync('mdx/android-debug.mdx');
        }
    }else{
        let out2 = require('child_process').spawnSync("ls", ["platforms/ios/mdx"]);
		console.log(out2.status);
		console.log(out2.stdout.toString());
        var file = ""
        var embedIPA = plugin.variables.EMBEDIPA;
        if(embedIPA){
            file = path.join("platforms/ios/mdx",projectName+"-exported.mdx")
        }else{
            file = path.join("platforms/ios/mdx",projectName+".mdx");
        }
        projectName = encodeURIComponent(projectName)
        if(!fs.existsSync(file)){
            log("MDX file doesn't exist!");
            return;
        }else{
            if(mode == "release"){
                baseUrl += "?type=release&platform=ios&name="+projectName;
                mdxFile = fs.readFileSync(file);
            }else{
                baseUrl += "?type=debug&platform=ios&name="+projectName;
                mdxFile = fs.readFileSync(file);
            }
        }
    }
    axios.post(baseUrl,mdxFile,{
        headers:{
            "Authorization": encryptedAuth
        },
	maxContentLength: Infinity,
	maxBodyLength: Infinity
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
