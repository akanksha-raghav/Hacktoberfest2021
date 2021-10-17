const { typeChecking } = require("./helper/index");

function compareObjects( obj1, obj2, options = { status: false, value: undefined } ) {
    if ( obj1 !== undefined && obj2 !== undefined ) {
        if ( ( Array.isArray(obj1) === false && typeof obj1 === "object" && obj1 !== null ) && ( Array.isArray(obj2) === false && typeof obj2 === "object" && obj2 !== null ) ) {
            let first_keys = Object.keys(obj1);
            let second_keys = Object.keys(obj2);

            let ansKeys;

            if ( first_keys.length === second_keys.length ) {
                if ( first_keys.length === 0 ) {
                    ansKeys = true;
                } else {
                    for ( let i = 0; i < first_keys.length; i++ ) {
                        // Next code is gonna start writing from here...
                        let val1 = ( typeof obj1[first_keys[i]] === "string") ? obj1[first_keys[i]].toUpperCase() : obj1[first_keys[i]];
                        let val2 = ( typeof obj2[second_keys[i]] === "string" ) ? obj2[second_keys[i]].toUpperCase() : obj2[second_keys[i]];

						if ( ( first_keys[i].toUpperCase() === second_keys[i].toUpperCase() ) ) {
							if ( Array.isArray(val1) && Array.isArray(val2) ) {
								if ( compareArrays(val1, val2) ) {
									ansKeys = true;
								} else {
									ansKeys = false;
									break;
								}
							} else if ( ( Array.isArray(val1) === false && Array.isArray(val2) === false ) && ( typeof val1 === "object" && typeof val2 === "object" ) ) {
								if ( compareObjects(val1, val2) ) {
									ansKeys = true;
								} else {
									ansKeys = false;
									break;
								}
							} else if ( (typeof val1 === "function") && (typeof val2 === "function") ) {
								if ( options.status ) {
									let s_check_val1 = val1(options.value);
									let s_check_val2 = val2(options.value);
									
									if ( s_check_val1 === s_check_val2 ) {
										ansKeys = true;
									} else {
										ansKeys = false;
										break;
									}
								} else {
									if ( val1.toString().replace(/\s+/g, '').trim() === val2.toString().replace(/\s+/g, '').trim() ) {
										ansKeys = true;
									} else {
										ansKeys = false;
										break;
									}
								}
							} else if ( val1 === val2 ) {
								ansKeys = true;
							} else {
								ansKeys = false;
								break;
							}
						} else {
							ansKeys = false;
						}
                    }
                }
            } else {
                ansKeys = false;
            }

            return ansKeys;
        } else throw new Error("Parameter should be objects");
    } else throw new Error("Both parameters are mendatory");
}

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


module.exports.compareObjects = compareObjects;