---
layout: post
title: "Lua load使用"
categories: Lua
tags: demo lua
author: linkzw
---

* content
{:toc}


Lua load的使用
 
	function execcode(code,env)
		local chunk
		if env == nil then
			chunk = load(code,"=(load)","bt")
		else
			chunk = load(code,"=(load)","bt",env)
		end
		return chunk()
	end
	function execformula(formula,params)
		local code = string.format("return %s",formula)
		return execcode(code,params)
	end

公式使用

	FuliExpFormula = "val * (0.5+0.5*(playerlv/50)^0.5) * fuli_addn * job_addn", 		
    -- 每周福利经验奖励公司(baseexp--基本经验，playerlv--玩家等级,fuli_addn--福利加成,job_addn--公会职位加成）
	local bonus.coin = execformula(data_1800_UnionVar.FiliExpFormula,{
		val = val,
		playerlv = player.lv,
		fuli_addn = fuli_addn,
		job_addn = job_addn,
	})
	




https://www.kancloud.cn/digest/lua-programming/204454