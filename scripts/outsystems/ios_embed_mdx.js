const fs = require('fs');
const path = require('path');

const common = require('../common');
const log = common.log;

/**
 * This just creates the mdx file from the settings described in mdx.json.
 */
module.exports = function(context) {
	const plugin = JSON.parse(fs.readFileSync(path.join(context.opts.projectRoot,"plugins", 'fetch.json'),"utf8"))[common.PluginId];
	const embedIPA = plugin.variables.EMBEDIPA
	if(embedIPA.toLowerCase() === "true"){
		log();
		log('===== Embeding MDX FOR IOS =====', 'cyan');

		process.chdir(context.opts.projectRoot);

		/** @type {'debug'|'release'} */
		let mode = get_mode(context);

		let mdx = JSON.parse(fs.readFileSync(common.MdxJson).toString());
		if (!mdx.hasOwnProperty('ios')) {
			log('No iOS options defined in mdx.json. Cannot create mdx file', 'red');
			return done();
		}

		let preferred = mdx['ios'][mode];
		if (preferred.hasOwnProperty('run')) {
			if (preferred['run'] == false) {
				log(`Run flag set to false for ${mode} in mdx.json. Not generating mdx...`, 'yellow');
				return done();
			}
		}
		let fallback = mdx['ios']['default'];
		if (fallback.hasOwnProperty('run')) {
			if (fallback['run'] == false) {
				log('Run flag set to false as default in mdx.json. Not generating mdx...', 'yellow');
				return done();
			}
		}
		
		
		let cmd = get_fatal_with_fallback(preferred, fallback, 'toolkit_dir');
		
		const ConfigParser = require("cordova-common").ConfigParser;
		const appConfig = new ConfigParser('config.xml');
		const projectName = appConfig.name();
		if(fs.existsSync("source/platforms/ios/build/device/"+projectName+".ipa")){
			console.log("ipa found");
		}
		
		let out2 = require('child_process').spawnSync("ls", ["platforms/ios/mdx"]);
		console.log(out2.status);
		console.log(out2.stdout.toString());

		if(!fs.existsSync("platforms/ios/mdx/"+projectName+".mdx")){
			console.log("MDX file doesn't exist!")
			return;
		}

		let args = [
			'SetInfo',
			'-in', "platforms/ios/mdx/"+projectName+".mdx",
			'-out', "platforms/ios/mdx/"+projectName+"-exported.mdx",
			'-embedBundle', "platforms/ios/build/device/"+projectName+".ipa"
		];
		console.log(cmd)
		console.log(args)

		let is_err = false;
		args.forEach((val, _i, _a) => {
			if (val === 0) is_err = true;
		})
		if (is_err) return done();

		log(`${cmd} ${args.join(' ')}`);
		
		let res = require('child_process').spawnSync(cmd, args);
		log(res.stdout.toString());

		let rv = res.status;
		if (rv === 0) log('Successfully created mdx file', 'green');
		else {
			log('Error generating mdx file', 'red');
			log('~~~~~ STDERR ~~~~~', 'red');
			log(res.stderr.toString(), 'red');
		}
		return done();
	}
}

function done() {
	log('===== DONE Embeding MDX FOR IOS =====', 'cyan');
	return 0;
}

/**
 * Retrieves from preferred if it exists. If it doesn't,
 * retrieve it from fallback.
 * @param {object} preferred the preferred objects
 * @param {object} fallback the fallback object
 * @param {string} key the key of the field
 * @returns {string|0}
 */
function get_fatal_with_fallback(preferred, fallback, key) {
	if (preferred.hasOwnProperty(key) && preferred[key] !== '') return preferred[key];
	if (fallback.hasOwnProperty(key) && fallback[key] !== '') return fallback[key];
	log(`${key} not defined!`, 'red');
	return 0;
}

/**
 * Accepts a path, returns the path localized to the platform
 * @param {string} pp
 * @returns {string|0}
 */
function platformize_path(pp) {
	if (typeof pp !== 'string') return 0;
	let is_absolute = path.isAbsolute(pp);
	let absolute_base;
	if (process.platform === 'win32') {
		absolute_base = pp.split('\\')[0];
	} else {
		absolute_base = '/';
	}
	// split using both / and \ as delimiters
	let tmp = pp.split(/\\\//);
	// recreate the path using current platform's delimiters
	let res = path.join(...tmp);
	if (is_absolute) {
		res = path.join(absolute_base, res);
	}
	return path.normalize(res);
}

/*
 * @param {object} context
 */
function get_mode(context) {
	if (context.cmdLine.indexOf('release') >= 0) return 'release';
	return 'debug';
}