const res = []


const isPrime = n => {
    if (n === 1) {
        return false
    } else if (n === 2) {
        return true
    } else {
        for (let x = 2; x < n; x++) {
            if (n % x === 0) {
                return false
            }
        }
        return true
    }
}

const primeBetween = (a, b) => {
    while (a <= b) {
        if (isPrime(a)) {
            res.push(a)
        }
        a++
    }
    return res
}


const sumPrime = (primes) => {
    return primes[primes.length - 2] + primes[primes.length - 1]
}

console.log(primeBetween(1, 10))
console.log(sumPrime(res))
