var xcode = require('xcode');
var fs = require('fs');
var path = require('path');

const xcodeProjPath = fromDir('platforms/ios', '.xcodeproj', false);
const projectPath = xcodeProjPath + '/project.pbxproj';
const myProj = xcode.project(projectPath);

module.exports = function(context) {
    var scriptPath = "plugins/cordova-plugin-mvpn/scripts/ios/buildPhase.txt";
    var script = "";
    if(fs.existsSync(scriptPath)){
        script = fs.readFileSync(scriptPath,"utf8");
        config = fs.readFileSync(path.join(context.opts.projectRoot, 'config.xml'),"utf8");
        var STOREURL = config.match(/variable name="STOREURL" value="(.*)"/g)
        var PACKAGEID = config.match(/variable name="PACKAGEID" value="(.*)"/g)
        var TEAMID = config.match(/variable name="TEAMID" value="(.*)"/g)
        if(STOREURL == null || PACKAGEID == null || TEAMID == null){
            return;
        }
        STOREURL = STOREURL[0].split('"')[3]
        PACKAGEID = PACKAGEID[0].split('"')[3]
        TEAMID = TEAMID[0].split('"')[3]
        script=script.replace(/\$STOREURL/g,STOREURL);
        script=script.replace(/\$PACKAGEID/g,PACKAGEID);
        script=script.replace(/\$TEAMID/g,TEAMID);
    }

    var options = { shellPath: '/bin/sh', shellScript: script };

    myProj.parse(function(err) {
    myProj.addBuildPhase([], 'PBXShellScriptBuildPhase', 'Create MDX Script',myProj.getFirstTarget().uuid, options);
    fs.writeFileSync(projectPath, myProj.writeSync());
    })
}

function getConfigParser(context, config){
    var semver = context.requireCordovaModule('semver');
  
    if(semver.lt(context.opts.cordova.version, '5.4.0')) {
      ConfigParser = context.requireCordovaModule('cordova-lib/src/ConfigParser/ConfigParser');
    } else {
      ConfigParser = context.requireCordovaModule('cordova-common/src/ConfigParser/ConfigParser');
    }
  
    return new ConfigParser(config);
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