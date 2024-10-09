func canAliceWin(nums []int) bool {
	aliceSum := 0
	bobSum := 0
	for _, value := range nums {
		if value >= 1 && value <= 9 {
			aliceSum += value
		} else {
			bobSum += value
		}
	}
	if aliceSum > bobSum {
		return true
	}
	aliceSum = 0
	bobSum = 0
	for _, value := range nums {
		if value >= 10 && value <= 99 {
			aliceSum += value
		} else {
			bobSum += value
		}
	}
	return aliceSum > bobSum
}