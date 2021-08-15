const fs = require('fs');
const path = require('path');

const common = require('../common');
const log = common.log;


log('===== CHANGING PACKAGE JSON =====', 'cyan');

let pkg = JSON.parse(fs.readFileSync(common.PackageJson).toString());
//add display name as in config.xml name

var ConfigParser = require("cordova-common").ConfigParser;
var appConfig = new ConfigParser('config.xml');
projectName = appConfig.name();

pkg["displayName"] = projectName;
//change name to bundleid

plugin = JSON.parse(fs.readFileSync(path.join("plugins", 'fetch.json'),"utf8"))[common.PluginId];
pkg["name"] = plugin.variables.BUNDLEID;

fs.writeFileSync(common.PackageJson,JSON.stringify(pkg));

log('===== FINISHED CHANGING PACKAGE JSON =====', 'cyan');