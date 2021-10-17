// This function is use for checking the type of the data.
function typeChecking(val) {
    let ans;
    if ( typeof val === "string" ) {
        ans = val.toUpperCase();
    } else if ( typeof val === "number" ) {
        ans = val;
    } else if ( typeof val === "boolean" ) {
        ans = val;
    } else if ( Array.isArray(val) === true ) {
        ans = "array"
    } else if ( typeof val === "object" ) {
        ans = "object";
    } else if ( typeof val === "function" ) {
        ans = "function"
    }

    return ans;
}

module.exports.typeChecking = typeChecking;