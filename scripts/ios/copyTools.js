const fs = require('fs');
const path = require('path');

const xcodeProjPath = "platforms/ios/Tools";
const toolsPath = "plugins/cordova-plugin-mvpn/Tools";

module.exports = function(context) {
    if(fs.existsSync(toolsPath)){
        copyFolderSync(toolsPath,xcodeProjPath);
    }
}

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