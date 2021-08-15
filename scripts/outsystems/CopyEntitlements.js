
const fs = require('fs');
const common = require('../common');
const log = common.log;

log('===== COPYING ENTITLEMENTS =====', 'cyan');
let pkg = JSON.parse(fs.readFileSync(common.PackageJson).toString());
	if (!pkg.hasOwnProperty('displayName')) {
		log('No display name defined in package.json. Are you sure this is a Cordova project?', 'red');
		return 0;
	}
let app_name = pkg['displayName'];

fs.copyFileSync("platforms/ios/"+app_name+"/Entitlements-Release.plist","platforms/ios/mdx.entitlements");

log('===== FINISHED COPYING ENTITLEMENTS =====', 'cyan');