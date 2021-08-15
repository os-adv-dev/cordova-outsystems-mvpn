var exec = require('cordova/exec');
const MAMCoreClass = 'CtxMAMCoreBridge';

exports.initializeSDKs = function (onInitializeSDKsSuccess, onInitializeSDKsError,...cordovaPlugins) {
    for (var i = 0; i < cordovaPlugins.length; i++) {
        if(cordovaPlugins[i]!=null && cordovaPlugins[i] !== undefined) {
            if(cordovaPlugins[i].initialize !== undefined) {
                cordovaPlugins[i].initialize();
            }
        }
    }
    exec(onInitializeSDKsSuccess, onInitializeSDKsError, MAMCoreClass, 'initializeSDKs');
};

exports.registerProxyServerSettingDetected = function (onProxyServerSettingDetected) {
    exec(onProxyServerSettingDetected, null, MAMCoreClass, 'proxyServerSettingDetected');
};

exports.registerSdksInitializedAndReady = function (onSdksInitializedAndReady) {
    exec(onSdksInitializedAndReady, null, MAMCoreClass, 'sdksInitializedAndReady');
};

exports.getConfigurationAsStringForKey = function (config, stringValue, onGetConfigurationAsStringForKeySuccess, onGetConfigurationAsStringForKeyFailure) {
    exec(onGetConfigurationAsStringForKeySuccess, onGetConfigurationAsStringForKeyFailure, MAMCoreClass, 'getConfigurationAsStringForKey', [config, stringValue]);
};

exports.getConfigurationAsNumberForKey = function (config, numberValue, onGetConfigurationAsNumberForKeySuccess, onGetConfigurationAsNumberForKeyFailure) {
    exec(onGetConfigurationAsNumberForKeySuccess, onGetConfigurationAsNumberForKeyFailure, MAMCoreClass, 'getConfigurationAsNumberForKey', [config, numberValue]);
};

exports.getConfigurationAsDataForKey = function (config, dataValue, onGetConfigurationAsDataForKeySuccess, onGetConfigurationAsDataForKeyFailure) {
    exec(onGetConfigurationAsDataForKeySuccess, onGetConfigurationAsDataForKeyFailure, MAMCoreClass, 'getConfigurationAsDataForKey', [config, dataValue]);
};

exports.getConfigurationAsDictionaryForKey = function (config, dictValue, onGetConfigurationAsDictionaryForKeySuccess, onGetConfigurationAsDictionaryForKeyFailure) {
    exec(onGetConfigurationAsDictionaryForKeySuccess, onGetConfigurationAsDictionaryForKeyFailure, MAMCoreClass, 'getConfigurationAsDictionaryForKey', [config, dictValue]);
};

exports.getConfigurationAsIntegerForKey = function (config, intValue, onGetConfigurationAsIntegerForKeySuccess, onGetConfigurationAsIntegerForKeyFailure) {
    exec(onGetConfigurationAsIntegerForKeySuccess, onGetConfigurationAsIntegerForKeyFailure, MAMCoreClass, 'getConfigurationAsIntegerForKey', [config, intValue]);
};

exports.getConfigurationAsDoubleForKey = function (config, doubleValue, onGetConfigurationAsDoubleForKeySuccess, onGetConfigurationAsDoubleForKeyFailure) {
    exec(onGetConfigurationAsDoubleForKeySuccess, onGetConfigurationAsDoubleForKeyFailure, MAMCoreClass, 'getConfigurationAsDoubleForKey', [config, doubleValue]);
};

exports.getConfigurationAsBoolForKey = function (config, boolValue, onGetConfigurationAsBoolForKeySuccess, onGetConfigurationAsBoolForKeyFailure) {
    exec(onGetConfigurationAsBoolForKeySuccess, onGetConfigurationAsBoolForKeyFailure, MAMCoreClass, 'getConfigurationAsBoolForKey', [config, boolValue]);
};

exports.getConfigurationAsObjectForKey = function (config, objectValue, onGetConfigurationAsObjectForKeySuccess, onGetConfigurationAsObjectForKeyFailure) {
    exec(onGetConfigurationAsObjectForKeySuccess, onGetConfigurationAsObjectForKeyFailure, MAMCoreClass, 'getConfigurationAsObjectForKey', [config, objectValue]);
};

exports.setConfigurationForStringKey = function (config, stringValue, onSetConfigurationForStringKeySuccess, onSetConfigurationForStringKeyFailure) {
    exec(onSetConfigurationForStringKeySuccess, onSetConfigurationForStringKeyFailure, MAMCoreClass, 'setConfigurationForStringKey', [config, stringValue]);
};

exports.setConfigurationForNumberKey = function (config, numberValue, onSetConfigurationForNumberKeySuccess, onSetConfigurationForNumberKeyFailure) {
    exec(onSetConfigurationForNumberKeySuccess, onSetConfigurationForNumberKeyFailure, MAMCoreClass, 'setConfigurationForNumberKey', [config, numberValue]);
};

exports.setConfigurationForDataKey = function (config, dataValue, onSetConfigurationForDataKeySuccess, onSetConfigurationForDataKeyFailure) {
    exec(onSetConfigurationForDataKeySuccess, onSetConfigurationForDataKeyFailure, MAMCoreClass, 'setConfigurationForDataKey', [config, dataValue]);
};

exports.setConfigurationForDictKey = function (config, dictValue, onSetConfigurationForDictKeySuccess, onSetConfigurationForDictKeyFailure) {
    exec(onSetConfigurationForDictKeySuccess, onSetConfigurationForDictKeyFailure, MAMCoreClass, 'setConfigurationForDictKey', [config, dictValue]);
};

exports.setConfigurationForIntKey = function (config, intValue, onSetConfigurationForIntKeySuccess, onSetConfigurationForIntKeyFailure) {
    exec(onSetConfigurationForIntKeySuccess, onSetConfigurationForIntKeyFailure, MAMCoreClass, 'setConfigurationForIntKey', [config, intValue]);
};

exports.setConfigurationForDoubleKey = function (config, doubleValue, onSetConfigurationForDoubleKeySuccess, onSetConfigurationForDoubleKeyFailure) {
    exec(onSetConfigurationForDoubleKeySuccess, onSetConfigurationForDoubleKeyFailure, MAMCoreClass, 'setConfigurationForDoubleKey', [config, doubleValue]);
};

exports.setConfigurationForBoolKey = function (config, boolValue, onSetConfigurationForBoolKeySuccess, onSetConfigurationForBoolKeyFailure) {
    exec(onSetConfigurationForBoolKeySuccess, onSetConfigurationForBoolKeyFailure, MAMCoreClass, 'setConfigurationForBoolKey', [config, boolValue]);
};

exports.setConfigurationForObjectKey = function (config, objectValue, onSetConfigurationForObjectKeySuccess, onSetConfigurationForObjectKeyFailure) {
    exec(onSetConfigurationForObjectKeySuccess, onSetConfigurationForObjectKeyFailure, MAMCoreClass, 'setConfigurationForObjectKey', [config, objectValue]);
};

exports.removeConfigurationForKey = function (config, onRemoveConfigurationForKeySuccess, onRemoveConfigurationForKeyFailure) {
    exec(onRemoveConfigurationForKeySuccess, onRemoveConfigurationForKeyFailure, MAMCoreClass, 'removeConfigurationForKey', [config]);
};

exports.getSharedConfigurationAsStringForKey = function (config, stringValue, onGetSharedConfigurationAsStringForKeySuccess, onGetSharedConfigurationAsStringForKeyFailure) {
    exec(onGetSharedConfigurationAsStringForKeySuccess, onGetSharedConfigurationAsStringForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsStringForKey', [config, stringValue]);
};

exports.getSharedConfigurationAsNumberForKey = function (config, numberValue, onGetSharedConfigurationAsNumberForKeySuccess, onGetSharedConfigurationAsNumberForKeyFailure) {
    exec(onGetSharedConfigurationAsNumberForKeySuccess, onGetSharedConfigurationAsNumberForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsNumberForKey', [config, numberValue]);
};

exports.getSharedConfigurationAsDataForKey = function (config, dataValue, onGetSharedConfigurationAsDataForKeySuccess, onGetSharedConfigurationAsDataForKeyFailure) {
exec(onGetSharedConfigurationAsDataForKeySuccess, onGetSharedConfigurationAsDataForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsDataForKey', [config, dataValue]);
};

exports.getSharedConfigurationAsDictionaryForKey = function (config, dictValue, onGetSharedConfigurationAsDictionaryForKeySuccess, onGetSharedConfigurationAsDictionaryForKeyFailure) {
    exec(onGetSharedConfigurationAsDictionaryForKeySuccess, onGetSharedConfigurationAsDictionaryForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsDictionaryForKey', [config, dictValue]);
};

exports.getSharedConfigurationAsIntegerForKey = function (config, intValue, onGetSharedConfigurationAsIntegerForKeySuccess, onGetSharedConfigurationAsIntegerForKeyFailure) {
    exec(onGetSharedConfigurationAsIntegerForKeySuccess, onGetSharedConfigurationAsIntegerForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsIntegerForKey', [config, intValue]);
};

exports.getSharedConfigurationAsDoubleForKey = function (config, doubleValue, onGetSharedConfigurationAsDoubleForKeySuccess, onGetSharedConfigurationAsDoubleForKeyFailure) {
    exec(onGetSharedConfigurationAsDoubleForKeySuccess, onGetSharedConfigurationAsDoubleForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsDoubleForKey', [config, doubleValue]);
};

exports.getSharedConfigurationAsBoolForKey = function (config, boolValue, onGetSharedConfigurationAsBoolForKeySuccess, onGetSharedConfigurationAsBoolForKeyFailure) {
    exec(onGetSharedConfigurationAsBoolForKeySuccess, onGetSharedConfigurationAsBoolForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsBoolForKey', [config, boolValue]);
};

exports.getSharedConfigurationAsObjectForKey = function (config, objectValue, onGetSharedConfigurationAsObjectForKeySuccess, onGetSharedConfigurationAsObjectForKeyFailure) {
    exec(onGetSharedConfigurationAsObjectForKeySuccess, onGetSharedConfigurationAsObjectForKeyFailure, MAMCoreClass, 'getSharedConfigurationAsObjectForKey', [config, objectValue]);
};

exports.setSharedConfigurationForStringKey = function (config, stringValue, onSetSharedConfigurationForStringKeySuccess, onSetSharedConfigurationForStringKeyFailure) {
    exec(onSetSharedConfigurationForStringKeySuccess, onSetSharedConfigurationForStringKeyFailure, MAMCoreClass, 'setSharedConfigurationForStringKey', [config, stringValue]);
};

exports.setSharedConfigurationForNumberKey = function (config, numberValue, onSetSharedConfigurationForNumberKeySuccess, onSetSharedConfigurationForNumberKeyFailure) {
    exec(onSetSharedConfigurationForNumberKeySuccess, onSetSharedConfigurationForNumberKeyFailure, MAMCoreClass, 'setSharedConfigurationForNumberKey', [config, numberValue]);
};

exports.setSharedConfigurationForDataKey = function (config, dataValue, onSetSharedConfigurationForDataKeySuccess, onSetSharedConfigurationForDataKeyFailure) {
    exec(onSetSharedConfigurationForDataKeySuccess, onSetSharedConfigurationForDataKeyFailure, MAMCoreClass, 'setSharedConfigurationForDataKey', [config, dataValue]);
};

exports.setSharedConfigurationForDictKey = function (config, dictValue, onSetSharedConfigurationForDictKeySuccess, onSetSharedConfigurationForDictKeyFailure) {
    exec(onSetSharedConfigurationForDictKeySuccess, onSetSharedConfigurationForDictKeyFailure, MAMCoreClass, 'setSharedConfigurationForDictKey', [config, dictValue]);
};

exports.setSharedConfigurationForIntKey = function (config, intValue, onSetSharedConfigurationForIntKeySuccess, onSetSharedConfigurationForIntKeyFailure) {
    exec(onSetSharedConfigurationForIntKeySuccess, onSetSharedConfigurationForIntKeyFailure, MAMCoreClass, 'setSharedConfigurationForIntKey', [config, intValue]);
};

exports.setSharedConfigurationForDoubleKey = function (config, doubleValue, onSetSharedConfigurationForDoubleKeySuccess, onSetSharedConfigurationForDoubleKeyFailure) {
    exec(onSetSharedConfigurationForDoubleKeySuccess, onSetSharedConfigurationForDoubleKeyFailure, MAMCoreClass, 'setSharedConfigurationForDoubleKey', [config, doubleValue]);
};

exports.setSharedConfigurationForBoolKey = function (config, objectValue, onSetSharedConfigurationForBoolKeySuccess, onSetSharedConfigurationForBoolKeyFailure) {
    exec(onSetSharedConfigurationForBoolKeySuccess, onSetSharedConfigurationForBoolKeyFailure, MAMCoreClass, 'setSharedConfigurationForBoolKey', [config, objectValue]);
};

exports.setSharedConfigurationForObjectKey = function (config, objectValue, onSetSharedConfigurationForObjectKeySuccess, onSetSharedConfigurationForObjectKeyFailure) {
    exec(onSetSharedConfigurationForObjectKeySuccess, onSetSharedConfigurationForObjectKeyFailure, MAMCoreClass, 'setSharedConfigurationForObjectKey', [config, objectValue]);
};

exports.removeSharedConfigurationForKey = function (config, onRemoveSharedConfigurationForKeySuccess, onRemoveSharedConfigurationForKeyFailure) {
    exec(onRemoveSharedConfigurationForKeySuccess, onRemoveSharedConfigurationForKeyFailure, MAMCoreClass, 'removeSharedConfigurationForKey', [config]);
};

exports.initializeCitrixLogger = function (onInitializeCitrixLogger) {
    exec(onInitializeCitrixLogger, null, MAMCoreClass, 'ctxMAMLog_Initialize');
};

exports.logCriticalError = function (source, fileName, functionName, lineNumber, message, onLogCriticalError) {
    exec(onLogCriticalError, null, MAMCoreClass, 'ctxMAMLog_CriticalErrorFrom', [source, fileName, functionName, lineNumber, message]);
};

exports.logError = function (source, fileName, functionName, lineNumber, message, onLogError) {
    exec(onLogError, null, MAMCoreClass, 'ctxMAMLog_ErrorFrom', [source, fileName, functionName, lineNumber, message]);
};

exports.logWarning = function (source, fileName, functionName, lineNumber, message, onLogWarning) {
    exec(onLogWarning, null, MAMCoreClass, 'ctxMAMLog_WarningFrom', [source, fileName, functionName, lineNumber, message]);
};

exports.logInfo = function (source, fileName, functionName, lineNumber, message, onLogInfo) {
    exec(onLogInfo, null, MAMCoreClass,'ctxMAMLog_InfoFrom', [source, fileName, functionName, lineNumber, message]);
};

exports.logDetail = function (source, fileName, functionName, lineNumber, message, onLogDetail) {
    exec(onLogDetail, null, MAMCoreClass, 'ctxMAMLog_DetailFrom', [source, fileName, functionName, lineNumber, message]);
};

exports.registerForNotifications = function (source, onRegisterForNotifications) {
    var contextId = uuidv4();
    exec(onRegisterForNotifications, null, 'CtxMAMCoreBridge', 'registerForNotifications', [source, contextId]);
    return contextId;
};

exports.deRegisterNotifications = function (source, callbackId, onDeRegisterNotificationsSuccess, onDeRegisterNotificationsError) {
    exec(onDeRegisterNotificationsSuccess, onDeRegisterNotificationsError, 'CtxMAMCoreBridge', 'deRegisterNotifications', [source, callbackId]);
};

function uuidv4() {
    return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
      var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
      return v.toString(16);
    });
}




