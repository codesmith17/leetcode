func longestWord(words []string) string {
	sort.Strings(words)
	mp := make(map[string]bool)
	longestWord := ""
	mp[""] = true
	for _, word := range words {
		parentWord := word[:len(word)-1]
		value, exists := mp[parentWord]
		if exists == true && value == true {
			if len(word) > len(longestWord) {
				longestWord = word
			}
			mp[word] = true
		}

	}
	return longestWord
}