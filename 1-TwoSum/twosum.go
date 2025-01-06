// go build -o bin/twosumgo twosum.go

package main

import "fmt"

func twoSum(nums []int, target int) []int {
	for x := 0; x < len(nums); x++ {
		for y := x + 1; y < len(nums); y++ {
			if nums[x]+nums[y] == target {
				fmt.Printf("%d, %d equals %d\n", x, y, target)
				return []int{x, y}
			}
		}
	}
	return nil
}

func twoSumHash(nums []int, target int) []int {
	cacheMap := make(map[int]int)
	cacheMap[nums[0]] = 0

	for i := 1; i < len(nums); i++ {
		temp := target - nums[i]
		if _, ok := cacheMap[temp]; ok {
			fmt.Printf("%d, %d equals %d\n", i, cacheMap[temp], target)
			return []int{i, cacheMap[temp]}
		}
		cacheMap[nums[i]] = i
	}
	return nil
}

func main() {
	twoSumHash([]int{2, 7, 11, 15}, 9)
	twoSumHash([]int{3, 2, 4}, 6)
	twoSumHash([]int{3, 3}, 6)
}

/*
first time doing go. I do not like the syntax much.
- curious why go prefers := over =
- the [] before the type is odd, but whatevs
- map[int]int looks really odd to me
- if _, ok := cacheMap[temp]; ok is really odd. I presume the _ is just a
  discard. The ok is a variable and then at the end it goes in if go is true/false.
  Its not easily knowable without knowing go is the main issue. Its too unique.
- TODO: Learn package vs import. I assume package is a bunch of stuff and import is a module
  in that package? need to learn.

I think if I had intellisense and better highlighting, it would be a tad easier.
Need to set that up next time.
*/
