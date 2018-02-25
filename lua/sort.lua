local arr = {31,41,59,26,41,58,}

function insert_sort(arr)
	for i = 2,#arr do
		local j = i - 1
		local key = arr[i]
		while j >= 1 and key < arr[j] do
			arr[j+1] = arr[j]
			j = j - 1
		end
		arr[j+1] = key
	end
	return arr
end

print("before_sort:",table.concat(arr,","))
print("after_sort:",table.concat(insert_sort(arr),","))
