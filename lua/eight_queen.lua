-- 8*8棋盘　每个皇后不能处于同一横行、纵行或斜线
--
local container = {}

local QUEEN_NUMBER = 8
function isvalid_queen(tab,queen_num)
	if #tab < queen_num then
		return false,"not enough number"
	end

end
