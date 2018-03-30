
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

-- 企业微信支持一键导出所有人账号和邮箱,格式如下
local name = [[
baidu;ali;tencent;
]]

local email = [[
baidu@china.com;ali@china.com;tencent@china.com;
]]

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

local ret = table.extend(string.split(name), string.split(email))
print(table.dump(ret))

--- 写入
print("-------开始写入--------")

local iostring = ""
for key,value in ipairs(ret) do
	iostring = string.format("%s\n%s\t:\t%s\n",iostring,value.name,value.email)
end

local outputfile = io.output("contacts.txt")
io.write(iostring)
io.flush()
io.close()

print("-------写入完成--------")
--- EOF
