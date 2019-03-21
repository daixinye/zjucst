/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    const morseMap = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    
    const a = 'a'.charCodeAt(0)
    const morseWordsMap = {}
    words.forEach(word => {
        let result = ""
        
        for(let i = 0; i < word.length; i++){
            let char = word[i]
            let index = char.charCodeAt(0) - a
            result += morseMap[index]
        }
        
        morseWordsMap[result] = 1
    })
    
    return Object.keys(morseWordsMap).length
    
};

console.log(uniqueMorseRepresentations(["gin", "zen", "gig", "msg"]))