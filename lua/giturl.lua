-- git url地址问题
-- 扫描文件结构 生成url地址

local url = "https://github.com"
local username = "wenruo95"
local branch = "blob"

local result = string.format("%s/%s/%s",url,username,branch,file_suffix)
print(result)
