const fs = require('fs');
const path = require('path');

var semver;

const xcodeProjPath = "platforms/ios/Tools";
const toolsPath = "plugins/cordova-plugin-mvpn/Tools";

module.exports = function(context) {
    if(fs.existsSync(toolsPath)){
        copyFolderSync(toolsPath,xcodeProjPath);
    }
    
    if(isCordovaAbove(context,8)){
    semver = require('semver');
    }else{
    semver = context.requireCordovaModule('semver');
    }
    var projectRoot = context.opts.projectRoot;

    var projectName = getConfigParser(context, path.join(projectRoot, 'config.xml')).name();
    fs.copyFileSync("platforms/ios/"+projectName+"/Entitlements-Release.plist","platforms/ios/"+projectName+".entitlements");

    function copyFolderSync(src, dest) {
        if (!fs.existsSync(dest)) fs.mkdirSync(dest)
      
        fs.readdirSync(src).forEach(dirent => {
          const [srcPath, destPath] = [src, dest].map(dirPath => path.join(dirPath, dirent))
          const stat = fs.lstatSync(srcPath)
      
          switch (true) {
            case stat.isFile():
                fs.copyFileSync(srcPath, destPath); break
            case stat.isDirectory():
                copyFolderSync(srcPath, destPath); break
            case stat.isSymbolicLink():
                fs.symlinkSync(readlinkSync(srcPath), destPath); break
          }
        })
    }
    function getConfigParser(context, config){
        if(semver.lt(context.opts.cordova.version, '5.4.0')) {
            ConfigParser = context.requireCordovaModule('cordova-lib/src/ConfigParser/ConfigParser');
        } else {
            ConfigParser = context.requireCordovaModule('cordova-common/src/ConfigParser/ConfigParser');
        }
      
        return new ConfigParser(config);
    }
    function isCordovaAbove (context, version) {
        var cordovaVersion = context.opts.cordova.version;
        console.log(cordovaVersion);
        var sp = cordovaVersion.split('.');
        return parseInt(sp[0]) >= version;
    }
}

