require "base"
-- 企业微信支持一键导出所有人账号和邮箱,格式如下
local name = [[
baidu;ali;tencent;
]]

local email = [[
baidu@china.com;ali@china.com;tencent@china.com;
]]

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
