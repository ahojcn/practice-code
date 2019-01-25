/**
* 这是针对数组进行操作的工具类
* @author ahoj
* @version V1.0
*/

public class ArrayTools {

	// 把构造方法私有，外界就不能再创建对象了
	private ArrayTools() {}

	/**
	* 这是遍历输出数组的方法
	* @param arr 是要被遍历的数组
	*/
	public static void printArray(int[] arr) {
		for (int i = 0; i < arr.length; i ++) {
			System.out.print(arr[i]);
		}
		System.out.println();
	}

	/**
	* 这是获取数组中最大值的方法
	* @param arr 是要获取最大值的数组
	* @return 返回数组中的最大值
	*/
	public static int getMax(int[] arr) {
		int max = arr[0];

		for (int i = 1; i < arr.length; i ++) {
			if(arr[i] > max) {
				max = arr[i];
			}
		}

		return max;
	}

	/**
	* 获取制定元素在数组中第一次出现的索引，如果元素不存在，返回-1
	* @param arr 被查找的数组
	* @param value 要查找的元素
	* @return 返回元素在数组中的索引，不存在返回-1
	*/
	public static int getIndex(int[] arr, int value) {
		int index = -1;

		for (int i = 0; i < arr.length; i ++) {
			if (arr[i] == value) {
				index = i;
				break;
			}
		}

		return index;
	}
}