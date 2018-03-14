-- git url地址问题
-- 扫描文件结构 生成url地址
-- 例子:markdown项目  https://github.com/wenruo95/markdown
-- 例子:markdown项目下test.txt https://github.com/wenruo95/blob/master/test.txt
local files = require("filename")

local url = "https://github.com"
local username = "wenruo95"
local branch = "blob/master"


--local result = string.format("%s/%s/%s",url,username,branch,file_suffix)
local result = {}
for repository_name,value in pairs(files) do
	local url_rep = string.format("%s/%s/%s",url,username,repository_name)
	local md_link_rp = string.format("## [%s](%s) \"%s\"",repository_name,url_rep,repository_name)
	table.insert(result,md_link_rp)
	for key,value in ipairs(value) do
		local md_url = string.format("%s/%s/%s/%s/%s",url,username,repository_name,branch,value.filename)
		local md_link = string.format("[%s](%s \"%s\")",value.title,md_url,value.title)
		table.insert(result,md_link)
	end
end
print(table.concat(result,"\n"))
local outputfile = io.output("menu.md")
io.write(table.concat(result,"\n"))
io.flush()
io.close()

-- 优化 将字符串输出到某个文件中
