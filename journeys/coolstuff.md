# A place to store Extra Cool stuff and learnings

[Carriage returns and same line overwriting coolness](#The-Carriage-return-Escape-Character-(\r))


[Referencing headers in markdown](#To-generate-the-indexes-or-links-to-headers-in-a-markdown-file)

## The Carriage return Escape Character (\r)

`\r` is carrage return escape character. Ever wondered how programs clear the line and write to the same line? or how do they **animate** command line programs? Well **this** is how they do it.

Example: Go sorting algorithm

```go
package main

import (
	"fmt"
	"time"
)

func BubbleSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-i-1; j++ {
			// len - i - 1, because the arr[len-1]th element has no arr[j+1], which we are using
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
				fmt.Printf("%v\r", arr)
				time.Sleep(2000 * time.Millisecond)
			}
		}
	}
	fmt.Println(arr)
}

func main() {
	var arr []int = []int{5, 3, 1, 2, 6, 7, 9, 4}
	BubbleSort(arr)
}
```