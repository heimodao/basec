
-- 打印table
function table.dump(t,space,name)
	if type(t) ~= "table" then
		return tostring(t)
	end
	space = space or ""
	name = name or ""
	local cache = { [t] = "."}
	local function _dump(t,space,name)
		local temp = {}
		for k,v in pairs(t) do
			local key = tostring(k)
			if cache[v] then
				table.insert(temp,"+" .. key .. " {" .. cache[v].."}")
			elseif type(v) == "table" then
				local new_key = name .. "." .. key
				cache[v] = new_key
				table.insert(temp,"+" .. key .. _dump(v,space .. (next(t,k) and "|" or " " ).. string.rep(" ",#key),new_key))
			else
				table.insert(temp,"+" .. key .. " [" .. tostring(v).."]")
			end
		end
		return table.concat(temp,"\n"..space)
	end
	return _dump(t,space,name)
end

function string.split(str)
	local ret = {}
	local pattern = string.format("[^%s]+",";")
	for s in string.gmatch(str,pattern) do
		if string.len(s) > 0 and s ~= " " then
			table.insert(ret,s)
		end
	end
	-- 移除最后一个多余
	table.remove(ret,#ret)
	return ret
end

--name email
function table.extend(tab1,tab2)
	local ret = {}
	for key,value in ipairs(tab1) do
		table.insert(ret,{
			name = value,
			email = tab2[key],
		})
	end
	return ret
end


