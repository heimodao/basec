-- a,b 均为字符串
function bigint_multiplication(a,b)
	a,b = tostring(a),tostring(b)
	-- 小数部分
	local result
	local point_a = string.len(a) - (string.find(a,"%.") or string.len(a))
	local point_b = string.len(b) - (string.find(b,"%.") or string.len(b))
	if point_a == 0 and point_b == 0 then
		result = _bigint_multiplication(math.floor(a),math.floor(b))
	else
		local nopoint_a = point_a and string.gsub(a,"%.","") or a
		local nopoint_b = point_b and string.gsub(b,"%.","") or b
		local int_result = _bigint_multiplication(nopoint_a,nopoint_b)
		local pointpos = (point_a or 1) * (point_b or 1)
		int_result = string.format("%s%s",string.rep("0",pointpos - string.len(int_result) + 1),int_result)
		result = string.format("%s.%s",string.sub(int_result,1,string.len(int_result) - pointpos),string.sub(int_result,string.len(int_result) - pointpos))
	end
	-- return string result
	print(string.format("%s * %s = %s\t%s",a,b,tonumber(a) * tonumber(b),result))
	return result
end

function _bigint_multiplication(a,b)
	a,b = tostring(a),tostring(b)
	local len_a,len_b = string.len(a),string.len(b)
	if len_a <= 4 and len_b <= 4 then
		return tonumber(a) * tonumber(b)
	end
	-- 如果长度不等则在字符串前加0至位数相等
	if len_a > len_b then
		b = string.format("%s%s",string.rep("0",len_a - len_b),b)
	elseif len_a < len_b then
		a = string.format("%s%s",string.rep("0",len_b - len_a),a)
	end
	-- 拆分ab
	local splitpos = math.ceil(string.len(a) / 2)
	local head_a,tail_a = string.sub(a,1,string.len(a) - splitpos),string.sub(a,-splitpos, -1)
	local head_b,tail_b = string.sub(b,1,string.len(b) - splitpos),string.sub(b,-splitpos, -1)
	-- 算出高位top，中位mid1,mid2,低位low
	local top = _bigint_multiplication(head_a,head_b)
	local mid = _bigplus(_bigint_multiplication(head_a,tail_b),_bigint_multiplication(tail_a,head_b))
	local low = _bigint_multiplication(tail_a,tail_b)
	low = string.format("%s%s",string.rep("0",splitpos - string.len(low)),low)
	--print(string.format("step1:a:%s\tb:%s\ttop:%s\tmid:%s\tlow:%s",a,b,top,mid,low))
	-- 进位
	local low_tail = string.sub(low,-splitpos,-1)
	local low_head = string.len(low) > splitpos and string.sub(low,1,string.len(low) - splitpos) or "0"
	-- 低位进位 + 中位
	local lowmid = _bigplus(low_head,mid)
	local lowmid_tail = string.sub(lowmid,-splitpos,-1)
	local lowmid_head = string.len(lowmid) > splitpos and string.sub(lowmid,1,string.len(lowmid) - splitpos) or "0"
	-- 中位进位 + 高位
	local midhigh = _bigplus(top,lowmid_head)
	local midhigh_tail = string.sub(midhigh,-splitpos,-1)
	local midhigh_head = string.len(midhigh) > splitpos and string.sub(midhigh,1,string.len(midhigh) - splitpos) or "0"
	--print(string.format("step2:midhigh_head:%s\tmidhigh_tail:%s\tlowmid_tail:%s\tlow_tail:%s",midhigh_head,midhigh_tail,lowmid_tail,low_tail))
	-- midhigh_head midhigh_tail lowmid_tail low_tail
	--local result = _bigplus(midhigh_head,0) .. _bigplus(midhigh_tail,0) .. _bigplus(lowmid_tail,0) .. _bigplus(low_tail,0)
	local result = string.format("%s%s%s%s",_bigplus(midhigh_head,0,true),midhigh_tail,lowmid_tail,low_tail)
	return result
end

function _bigplus(a,b,tip)
	a,b = tostring(a),tostring(b)
	local len_a,len_b = string.len(a),string.len(b)
	-- 如果长度不等则在字符串前加0至位数相等
	if len_a > len_b then
		b = string.format("%s%s",string.rep("0",len_a - len_b),b)
	elseif len_a < len_b then
		a = string.format("%s%s",string.rep("0",len_b - len_a),a)
	end
	local result = {}
	for key = string.len(a),1,-1 do
		local inc = 0
		if result[key+1] and result[key+1] >= 10 then
			inc = math.floor(result[key+1] / 10)
			result[key+1] = result[key+1] - inc * 10
		end
		result[key] = tonumber(string.sub(a,key,key)) + tonumber(string.sub(b,key,key)) + inc
	end
	-- 去0
	if tip then
		local retresult = {}
		local flag
		for key,value in ipairs(result) do
			if not flag and value ~= 0 then
				flag = true
			end
			if flag then
				table.insert(retresult,value)
			end
		end
		return table.concat(retresult,"")
	end
	return table.concat(result,"")
end

--[[
print("123 + 456",_bigplus(123,456),123 + 456)
print("1234 + 4567",_bigplus(1234,4567),1234 + 4567)
print("12345 + 45678",_bigplus(12345,45678),12345 + 45678)
print("123456 + 456789",_bigplus(123456,456789),123456 + 456789)
print("1234567 + 4567890",_bigplus(1234567,4567890),1234567 + 4567890)
]]

-- test
bigint_multiplication(12,34)
bigint_multiplication(123,345)
bigint_multiplication(12345789000,345673728)
bigint_multiplication(12345,345678)
bigint_multiplication(123451231.6,345.678)
bigint_multiplication(123456789999,3456.78)
bigint_multiplication(12345,3456789)

