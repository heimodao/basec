// 纯手打，估计会有不少语法错误

public class Datahandle {
	static class Data {
		integer id;
		string title;
		ArrayList<string> keys;
	}

	static ArrayList<Data> data;
	// key id
	static HashMap<string,ArrayList<integer>> map;
	
	// 返回重复元素
	ArrayList<string> common_keys(ArrayList<String> list1,ArrayList<string> list2) {
		ArrayList<string> common;
		// list1转化为set listset.addAll(list1)
        Set<String> listSet = new HashSet<String>(list1);
		
		// 遍历list2
		for (int i = 0; i < list2.size(); i++) {
			if (listset.contains(list2[i])) {
				common.add(list2[i]);
			}
		}
		return common;
		
	}

	public static void main(string args[]) {
		// 优化:1、2可以一次完成
		// 1.data初始化 ==> 数据导入
		data_init();
		
		// 2.所有数据导入map
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data[i].keys.size(); j++) {
				if (map.get(data[i].keys[j]) == NULL) {
					map.put(data[i].keys[i],{data[i].id});	
				} else {
					ArrayList<integer> arr = data[i].keys;
					arr.add(arr.size() + 1,data[i].id);
					map.put(data[i].keys[j],arr);					
				}
			}
		}
		
		// 遍历
		// [0] 0 2 3 4 5 6
		// [1] 0 0 3 4 5 6
		integer common[data.size()][data.size()] = {0}; 
		for (int i = 0; i < data.size(); i++) {
			// 遍历keys
			for (int j = 0; j < data[i].keys.size(); j++) {
				ArrayList<integer> ids = map.getvalues(data[i].keys[j]);
				if (common[i][j] == 0) {
					for (int k = 0; k < ids.size(); k++) {
						common[i][ids[k]]++;
					}
				} else {
					common[i][j] = common[j][i];					
				}
			}
		}
		
		// common 是一个对称矩阵，common[i][j]== common[j][i] ,也就是id为i的和id为j的共同元素是相同的
		// 时间复杂度仅比所有数据两两比对要好，这里只计算出i和j有多少个共同元素
		// 如果需要指导具体有哪些重复元素，common_keys(data[i].keys,data[j].keys)
	}
}