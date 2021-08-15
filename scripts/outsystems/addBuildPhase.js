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
    var scriptPath = "plugins/cordova-plugin-mvpn/scripts/outsystems/buildPhase.txt";
    var script = "";
    if(fs.existsSync(scriptPath)){
        script = fs.readFileSync(scriptPath,"utf8");
        plugin = JSON.parse(fs.readFileSync(path.join(context.opts.projectRoot,"plugins", 'fetch.json'),"utf8"))[common.PluginId];

        var STOREURL = plugin.variables.STOREURL;
        var PACKAGEID = plugin.variables.PACKAGEID;
        var TEAMID = plugin.variables.TEAMID;
        if(STOREURL == null || PACKAGEID == null || TEAMID == null){
          console.log("Missing variable (STOREURL || PACKAGEID || TEAMID)!")
            return;
        }
        script=script.replace(/\$STOREURL/g,STOREURL);
        script=script.replace(/\$PACKAGEID/g,PACKAGEID);
        script=script.replace(/\$TEAMID/g,TEAMID);
    }else{
      log("Script Not Found!","red")
      return;
    }

    var options = { shellPath: '/bin/sh', shellScript: script };

    myProj.parse(function(err) {
      if(err != null || err != undefined){
        console.log(err)
      }
    myProj.addBuildPhase([], 'PBXShellScriptBuildPhase', 'Create MDX Script',myProj.getFirstTarget().uuid, options);
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