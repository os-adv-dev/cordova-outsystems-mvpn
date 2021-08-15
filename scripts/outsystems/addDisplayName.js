const fs = require('fs');
const path = require('path');

const common = require('../common');
const log = common.log;
const pluginId = "cordova-plugin-core"


log('===== CHANGING PACKAGE JSON =====', 'cyan');

let pkg = JSON.parse(fs.readFileSync(common.PackageJson).toString());
//add display name as in config.xml name

var ConfigParser = require("cordova-common").ConfigParser;
var appConfig = new ConfigParser('config.xml');
projectName = appConfig.name();

pkg["displayName"] = projectName;

fs.writeFileSync(common.PackageJson,JSON.stringify(pkg));

log('===== FINISHED CHANGING PACKAGE JSON =====', 'cyan');