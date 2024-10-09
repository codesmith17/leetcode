func isDigitSumEven(num int) bool {
	sum := 0
	for num > 0 {
		sum += num % 10
		num /= 10
	}
	return sum%2 == 0
}
func countEven(num int) int {
	cnt := 0
	for i := 1; i <= (num); i++ {
		if isDigitSumEven(i) {
			cnt++
		}
	}
	return cnt
}