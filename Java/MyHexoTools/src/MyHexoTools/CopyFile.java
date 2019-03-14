package MyHexoTools;

import java.io.File;

public class CopyFile {
	public static void main(String[] args) {
		// 删除 /Users/hanoi_ahoj/Hexo/public/wiki 下的所有文件
		File wiki = new File("/Users/hanoi_ahoj/Hexo/public/wiki");
		delDir(wiki);
		
		// 复制所有文件 /Users/hanoi_ahoj/Hexo/wiki_hexo/public => /Users/hanoi_ahoj/Hexo/public/wiki
	}

	public static void delDir(File file) {
	    if (file.isDirectory()) {
	        File zFiles[] = file.listFiles();
	        for (File file2 : zFiles) {
	            delDir(file2);
	        }
	        System.out.println(file.getName() + " : delete");
	        file.delete();
	    } else {
	    	System.out.println(file.getName() + " : delete");
	        file.delete();
	    }
	}
}
