
function fibonacci(n)
	if n == 0 or n == 1 then
		return 1
	else
		return fibonacci(n-1) + fibonacci(n-2)
	end
end


for i = 1,30 do
	print(fibonacci(i))
end
