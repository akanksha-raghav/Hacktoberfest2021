document.getElementById('english_message').addEventListener('input', el => {
  const english_message = el.target.value;
  
  // PIG LATIN LOGIC
  function pigLatin(str) {
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let new_str = "";
    let arr = str.split(' ');
    
    let pig_latin = arr.map(word => {
      if (vowels.indexOf(word[0]) > -1) {
        new_str = word + "way";
        return new_str;
      } else {
        let firstMatch = word.match(/[aeiou]/) || 0;
        let vowel = word.indexOf(firstMatch);
        new_str = word.substring(vowel) + word.substring(0, vowel) + "ay";
        return new_str;
      }
    });
    
    return pig_latin.join(' ');
  }
  
  const pig_latin_message = pigLatin(english_message);
  document.getElementById('translation').innerHTML = pig_latin_message;
});