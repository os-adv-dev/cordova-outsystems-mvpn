const path = require('path');
var uuidgen;

// these locations are just for consistency
module.exports.MdxJson = 'mdx.json';
module.exports.BuildJson = 'build.json';
module.exports.PackageJson = 'package.json';
module.exports.Entitlements = path.join('platforms', 'ios', 'mdx.entitlements');

module.exports = function(context) {

	if(isCordovaAbove(context,8)){
		uuidgen = require('uuid/v4');
	}else{
		uuidgen = context.requireCordovaModule('uuid/v4');
	}


}


// function that just generates a random number
module.exports.rand = () => uuidgen().split('-').join('');

/**
 * Possibly prints a message, possibly in a certain color, but definitely prints a new line.
 * @param {string} [message=] the message to print
 * @param {'white'|'red'|'yellow'|'green'|'cyan'} [color=] the color to print with
 */
function log(message, color) {
	if (message === undefined) {
		console.log(); 
		return;
	}
	if (color === undefined) {
		console.log(message);
		return;
	}
	let color_code = get_color_code(color);
	console.log('%s%s\x1b[0m', color_code, message);
}
module.exports.log = log;

/**
 * Gets a color code for a certain color
 * @param {'red'|'yellow'|'green'|'white'|'cyan'} [color='white'] the color
 */
function get_color_code(color) {
	if (color === 'red') return '\x1b[31m';
	if (color === 'yellow') return '\x1b[33m';
	if (color === 'green') return '\x1b[32m';
	if (color === 'cyan') return '\x1b[36m';
	return '\x1b[37m';
}
function isCordovaAbove (context, version) {
	var cordovaVersion = context.opts.cordova.version;
	console.log(cordovaVersion);
	var sp = cordovaVersion.split('.');
	return parseInt(sp[0]) >= version;
  }