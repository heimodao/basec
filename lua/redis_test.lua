os.execute("pwd")

local password = arg[1] or "password"
print(string.format("password:%s",password))
for port = 6350,6390 do
	os.execute(string.format("redis-cli -p %s -a %s dbsize",port,password))
	os.execute(string.format("redis-cli -p %s -a %s pubsub channels",port,password))
end
