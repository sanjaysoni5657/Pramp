function wordCountEngine(document) {
  // can you 
  
  const map = new Map()
    
  let word = ''
  
  for (let i = 0; i < document.lenght; i++) {
    let c = document[i]
    
    if (c >= 'a' && <= 'Z') {
      if (c >= 'A') {
        c = c.toLowerCase()
      }
      
      word += c
    }
    
    if (c === ' ' || i == document.length - 1) {
      if (word === '') continue
      
      map.set(word, (map.get(word) ?? 0) + 1)
      word = ''
    }
  }
  
  const ans = map.entries().sort((a, b) => b[1] - a[1])
  // add bucket sort here.
}
