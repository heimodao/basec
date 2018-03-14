-- git url地址问题
-- 扫描文件结构 生成url地址
-- 例子:markdown项目  https://github.com/wenruo95/markdown
-- 例子:markdown项目下test.txt https://github.com/wenruo95/blob/master/test.txt
local files = require("filename")

local url = "https://github.com"
local username = "wenruo95"
local branch = "blob/master"


local result = {}
for repository_name,value in pairs(files) do
	local url_rep = string.format("%s/%s/%s",url,username,repository_name)
	local title = string.gsub(repository_name,"/",":")
	local md_link_rp = string.format("## [%s](%s \"%s\")",title,url_rep,repository_name)
	table.insert(result,md_link_rp)
	-- 内部元素升序排列
	table.sort(value,function(a,b)
		return a.filename < b.filename
	end)
	for key,value in ipairs(value) do
		local md_url = string.format("%s/%s/%s/%s/%s",url,username,repository_name,branch,value.filename)
		local md_link = string.format("[%s](%s \"%s\")",value.title,md_url,value.title)
		table.insert(result,md_link)
	end
end
local str = table.concat(result,"\n\n")
print(str)

print("--------开始写入--------")
local outputfile = io.output("menu.md")
io.write(str .. "\n\n")
io.flush()
io.close()
--[[
local outputfile = io.open("../README.md","a")
io.output(outputfile)
io.write(str)
io.close(outputfile)
]]
print("--------写入完成--------")

