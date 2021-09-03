var xcode;
const fs = require('fs');
const path = require('path');

const common = require('../common');
const log = common.log;

const xcodeProjPath = fromDir('platforms/ios', '.xcodeproj', false);
const projectPath = xcodeProjPath + '/project.pbxproj';
var myProj;

module.exports = function(context) {
    function isCordovaAbove (context, version) {
      var cordovaVersion = context.opts.cordova.version;
      var sp = cordovaVersion.split('.');
      return parseInt(sp[0]) >= version;
    }
    log("====Started Adding MDX Create Build Script!====")
    if(isCordovaAbove(context,8)){
      xcode = require('xcode');
    }else{
      xcode = context.requireCordovaModule('xcode');
    }
    myProj = xcode.project(projectPath);
    var mdxScriptPath = "plugins/cordova-plugin-mvpn/scripts/outsystems/buildPhaseMDX.txt";
    var embedScriptPath = "plugins/cordova-plugin-mvpn/scripts/outsystems/buildPhaseEmbed.txt";

    plugin = JSON.parse(fs.readFileSync(path.join(context.opts.projectRoot,"plugins", 'fetch.json'),"utf8"))[common.PluginId];

    var mdxScript = "";
    if(fs.existsSync(mdxScriptPath)){
      mdxScript = fs.readFileSync(mdxScriptPath,"utf8");

        var STOREURL = plugin.variables.STOREURL;
        var PACKAGEID = plugin.variables.PACKAGEID;
        var TEAMID = plugin.variables.TEAMID;
        if(STOREURL == undefined || PACKAGEID == undefined || TEAMID == undefined){
          console.log("Missing variable (STOREURL || PACKAGEID || TEAMID)!")
            return;
        }
        mdxScript=mdxScript.replace(/\$STOREURL/g,STOREURL);
        mdxScript=mdxScript.replace(/\$PACKAGEID/g,PACKAGEID);
        mdxScript=mdxScript.replace(/\$TEAMID/g,TEAMID);
        var mdxOptions = { shellPath: '/bin/sh', shellScript: mdxScript };
    }else{
      log("MDX Script Not Found!","red")
    }
/*
    const embedIPA = plugin.variables.EMBEDIPA

    var embedScript = "";
    if(fs.existsSync(embedScriptPath)){
      embedScript = fs.readFileSync(embedScriptPath,"utf8");

      var extension = path.extname(xcodeProjPath);
      var EXECUTABLENAME = path.basename(xcodeProjPath,extension);

      var IPAFILEPATH = path.join("source","platforms","ios","build","device",EXECUTABLENAME+".ipa");

      embedScript=embedScript.replace(/\$IPAFILEPATH/g,IPAFILEPATH);
      embedScript=embedScript.replace(/\$EXECUTABLENAME/g,EXECUTABLENAME);
      var embedOptions = { shellPath: '/bin/sh', shellScript: embedScript };
  }else if(embedIPA){
    log("Embed Script Not Found!","red")
  }
  */

    
    

    myProj.parse(function(err) {
      if(err != null || err != undefined){
        console.log(err)
      }
      if (mdxScript != ""){
        myProj.addBuildPhase([], 'PBXShellScriptBuildPhase', 'Create MDX Script',myProj.getFirstTarget().uuid, mdxOptions);        
      }
      /*
      if (embedScript != ""){
        myProj.addBuildPhase([], 'PBXShellScriptBuildPhase', 'Embed MDX Script',myProj.getFirstTarget().uuid, embedOptions);
      }*/
      
    fs.writeFileSync(projectPath, myProj.writeSync());
    log("====Finished Adding MDX Create Build Script!====")
    })
}

function fromDir(startPath, filter, rec, multiple) {
  if (!fs.existsSync(startPath)) {
    console.log("no dir ", startPath);
    return;
  }
  const files = fs.readdirSync(startPath);
  var resultFiles = [];
  for (var i = 0; i < files.length; i++) {
    var filename = path.join(startPath, files[i]);
    var stat = fs.lstatSync(filename);
    if (stat.isDirectory() && rec) {
      fromDir(filename, filter); //recurse
    }

    if (filename.indexOf(filter) >= 0) {
      if (multiple) {
        resultFiles.push(filename);
      } else {
        return filename;
      }
    }
  }
  if (multiple) {
    return resultFiles;
  }
}