local chartoNumber = {
	["〇"] = 0, ["一"] = 1, ["二"] = 2, ["三"] = 3, ["四"] = 4, ["五"] = 5, ["六"] = 6, ["七"] = 7, ["八"] = 8, ["九"] = 0, 
	["零"] = 0, ["壹"] = 1, ["贰"] = 2, ["叁"] = 3, ["肆"] = 4, ["伍"] = 5, ["陆"] = 6, ["柒"] = 7, ["捌"] = 8, ["玖"] = 0, 
}

local numberToChar = {
	[0] = {"零","〇",0,"zero",},
	[1] = {"壹","一",1,"one",},
	[2] = {"贰","二",2,"two",},
	[3] = {"叁","三",3,"three",},
	[4] = {"肆","四",4,"four",},
	[5] = {"伍","五",5,"five",},
	[6] = {"陆","六",6,"six",},
	[7] = {"柒","七",7,"seven",},
	[8] = {"捌","八",8,"eight",},
	[9] = {"玖","九",9,"nine",},
}

local function numtostr(num)
	num = tostring(assert(tonumber(num)))
	local str = {}
	string.gsub(num,".",function(c)
		table.insert(str,numberToChar[tonumber(c)][math.random(1,2)])
	end)
	return table.concat(str,"")
end

local seed = 10086
local function getseed()
	seed = seed + 1
	if seed > 10000 then
		seed = 1
	end
	return seed
end

-- math.random([n,[m]])
-- 三种用法：(0,1)的随机浮点数 (1,n)随机整数 (n,m)随机整数
local function randcode()
	-- 序列种子相同随机数必定相同,设置一个自增长的序列种子,范围为[1,10000]
	-- math.randomseed(tostring(os.time()):reverse():sub(1,6))
	--math.randomseed(getseed())
	local num1 = math.random(0,100)
	--math.randomseed(getseed())
	local num2 = math.random(0,100)
	local rightresult = num1 + num2
	local operator = "+"
	local msg = string.format("请输入%s %s %s = %d",numtostr(num1),operator,numtostr(num2),rightresult)
	print(msg)
	return rightresult
end

for i = 1,100 do
	randcode()
end












