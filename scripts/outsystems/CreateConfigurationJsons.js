const fs = require('fs');
const path = require('path');

const common = require('../common');
const log = common.log;


plugin = JSON.parse(fs.readFileSync(path.join("plugins", 'fetch.json'),"utf8"))[common.PluginId];

//create mdx.json file
var mdxjson = {}
log("======Start creating configuration files MDX and build=====",'cyan')
if(!fs.existsSync(common.MdxJson)){
    mdxjson = get_default_MDX();

    mdxjson.ios.default.storeUrl = plugin.variables.STOREURL
    mdxjson.ios.default.packageId = plugin.variables.PACKAGEID
    mdxjson.ios.default.appIdPrefix = plugin.variables.TEAMID
}else{
    mdxjson = JSON.parse(fs.readFileSync(common.MdxJson));

    mdxjson.ios.default.storeUrl = plugin.variables.STOREURL
    mdxjson.ios.default.packageId = plugin.variables.PACKAGEID
    mdxjson.ios.default.appIdPrefix = plugin.variables.TEAMID
}
fs.writeFileSync(common.MdxJson,JSON.stringify(mdxjson));
log("======Finished creating MDX configuration file=====",'cyan')

function get_default_MDX() {
	let pkg = JSON.parse(fs.readFileSync(common.PackageJson).toString());
	if (!pkg.hasOwnProperty('displayName')) {
		log('No display name defined in package.json. Are you sure this is a Cordova project?', 'red');
		return 0;
	}
	let app_name = pkg['displayName'];
	return {
		'ios': {
			'default': {
				'toolkit_dir':'platforms/ios/Tools/CGAppCLPrepTool',
				'app': 'platforms/ios/build/device/'+app_name+'.app',
				'storeUrl': '',
				'appType': 'sdkapp',
				'packageId': '',
				'entitlements': 'platforms/ios/mdx.entitlements',
				'appIdPrefix': '',
				'minPlatform': '11.0',
			},
			'debug': {
				'mdx': 'mdx/ios-debug.mdx'
			},
			'release': {
				'mdx': 'mdx/ios-release.mdx'
			}
		}
	}
}

//add to build.json the missing keys
var buildjson = {}
if(!fs.existsSync(common.BuildJson)){
    buildjson = get_default_Build();

    buildjson.ios.debug.storeUrl = plugin.variables.STOREURL
    buildjson.ios.debug.uuid = plugin.variables.PACKAGEID
    buildjson.ios.debug.appIdPrefix = plugin.variables.TEAMID

    buildjson.ios.release.storeUrl = plugin.variables.STOREURL
    buildjson.ios.release.uuid = plugin.variables.PACKAGEID
    buildjson.ios.release.appIdPrefix = plugin.variables.TEAMID
}else{
    buildjson = JSON.parse(fs.readFileSync(common.BuildJson));

    buildjson.ios.debug.storeUrl = plugin.variables.STOREURL
    buildjson.ios.debug.uuid = plugin.variables.PACKAGEID
    buildjson.ios.debug.appIdPrefix = plugin.variables.TEAMID

    buildjson.ios.release.storeUrl = plugin.variables.STOREURL
    buildjson.ios.release.uuid = plugin.variables.PACKAGEID
    buildjson.ios.release.appIdPrefix = plugin.variables.TEAMID
}
fs.writeFileSync(common.BuildJson,JSON.stringify(buildjson));
log("======Finished creating configuration build file=====",'cyan')

function get_default_Build() {
	return {
		'ios': {
			'debug': {
				'uuid':'',
				'storeUrl': '',
				'appIdPrefix': ''
			},
			'release': {
				'uuid':'',
				'storeUrl': '',
				'appIdPrefix': ''
			}
		}
	}
}