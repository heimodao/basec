
for value = 1,15 do
	local rsa = (value ^ 3) % 10
	local final = (rsa ^ 3) % 10
	print(string.format("before:%d\trsa:%d\tend:%d\t",value,rsa,final))
end
