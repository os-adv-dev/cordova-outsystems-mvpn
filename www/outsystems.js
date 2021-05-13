document.addEventListener("deviceready",this.onDeviceReady,false);
module.exports = {
    onDeviceReady: function() {
        this.receivedEvent('deviceready');
        if (this.mvpnAvailable()) {
            cordova.InAppBrowser.open = mvpn.InAppBrowser.open; // If you are using InAppBrowser
            cordovaFetch = mvpnFetch; // If you are using cordova-plugin-fetch
        }
    },
	mvpnAvailable: function() {
        try {
            let tmp = mvpn;
            tmp = mvpnFetch;
            console.log('MVPN SDK detected.');
            return true;
        } catch (e) {
            console.error('No MVPN SDK');
            return false;
        }
    }
}