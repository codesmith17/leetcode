func averageWaitingTime(customers [][]int) float64 {
	n := len(customers)
	var waitTime int64 = int64(customers[0][1])
	var startTime int = customers[0][1] + customers[0][0]
	for i := 1; i < n; i++ {
		if startTime > customers[i][0] {
			waitTime += int64(startTime) - int64(customers[i][0])
		} else {
			startTime = (customers[i][0])
		}
		waitTime += int64(customers[i][1])
		startTime += customers[i][1]
	}
	return float64(waitTime) / float64(n)
}