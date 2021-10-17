const { compareObjects } = require("./object");
const { typeChecking } = require("./helper/index");

function compareArrays( ar1, ar2 ) {
    let ans;
    if ( ( ar1 === undefined ) || (ar2 === undefined) ) {
        ans = false;
    } else {
        if ( ar1.length === ar2.length && (ar1.length !== 0) ) {
            for ( let i = 0; i < ar1.length; i++ ) {
                const val1 = typeChecking(ar1[i]);
                const val2 = typeChecking(ar2[i]);
                if ( (val1 === "array") && (val2 === "array") ) {
                    if ( compareArrays(ar1[i], ar2[i]) ) {
                        ans = true;
                    } else {
                        ans = false;
                        break;
                    }
                } else if ( (val1 === "object") && (val2 === "object") ) {
                    if ( compareObjects(ar1[i], ar2[i]) ) {
                        ans = true;
                    } else {
                        ans = false;
                        break;
                    }
                } else if ( val1 === val2 && (val1 !== "array" && val1 !== "object") && (val2 !== "object" && val2 !== "array") ) {
                    ans = true;
                } else {
                    ans = false;
                    break;
                }
            }
        } else if ( ar1.length === 0 && ar2.length === 0 ) {
            ans = true;
        } else {
            ans = false;
        }
    }

    return ans;
}

module.exports.compareArrays = compareArrays;