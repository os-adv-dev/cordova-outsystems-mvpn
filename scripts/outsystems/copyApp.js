
const fs = require('fs');
const common = require('../common');
const log = common.log;

log('===== COPYING APP =====', 'cyan');
let pkg = JSON.parse(fs.readFileSync(common.PackageJson).toString());
	if (!pkg.hasOwnProperty('displayName')) {
		log('No display name defined in package.json. Are you sure this is a Cordova project?', 'red');
		return 0;
	}
let app_name = pkg['displayName'];

let res2 = require('child_process').spawnSync("ls", ["-l","platforms/ios/build/device"]);
log(res2.stdout.toString());

//let resReadLink = require('child_process').spawnSync("readlink", ["-f",platformize_path(get_fatal_with_fallback(preferred, fallback, 'app'))]);
//let appPath = resReadLink.stdout.toString();

//let statApp = fs.statSync("platforms/ios/build/device/"+app_name+".app")
//log(statApp)
let res3 = require('child_process').spawnSync("readlink", ["platforms/ios/build/device/"+app_name+".app"]);
log(res3.stdout.toString());
let statApp = fs.readlinkSync("platforms/ios/build/device/"+app_name+".app")
log(statApp)
let statApp2 = statApp.split("/")
statApp2.pop()
statApp = statApp2.join("/");
log(statApp)
let res = require('child_process').spawnSync("ls", ["-l",statApp]);
log(res.stdout.toString());
    

//fs.copyFileSync(statApp2,"platforms/ios/build/device/"+app_name+".app");
let out = require('child_process').spawnSync("chmod", ["777","platforms/ios/build/device/"+app_name+".app"]);
log("==")
log(out.stdout.toString())

log('===== FINISHED COPYING APP =====', 'cyan');