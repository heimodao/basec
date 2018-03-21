---
layout: post
title: "java输入的几种方式"
categories: java 
excerpt: java输入的几种方式
---

* content
{:toc}



## 前言

这个是我在做浙大的acm中的第一道题A+B problem的源码   

写点东西记录一下我的做题过程吧，以下是我们在java输入中较为常用的方法   

---

## 第一种：Scanner类

这个是最为简单而又是最为强大的，比较常用   

	Scanner sc= new Scanner(System.in); 
	while (sc.hasNextInt()) {
		int a=sc.nextInt();
		int b=sc.nextInt();
		System.out.println(a+b);
	}

当然，如果想要输入String、float等类型同理   

	float f=sc.nextFloat();
	String c=sc.nextLine();
	System.out.println("字符串:"+c+"浮点型:"+f);

## 第二种：BufferedReader类和InputStreamReader类

这个就略微有点麻烦，用的比较少，从控制台接收一个字符串，然后将其打印出来。   

	public static void main(String[] args) {  
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = null;
		System.out.println("请输入字符串:");
		try {
			str = br.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("输入字符串为:"+str);

	}

## 第三种：从控制台接收一个字符，然后将其打印出来

这个就属于那种基本不怎么用了，下载开发通常都是用的ide，很少会在直接在控制台上只用一个jdk进行开发，不过这种方法初学者都用的比较多吧   

	public static void main(String[] args)throw IOException{
                System.out.print("Enter a Char:");
                char i = (char)System.in.read();
                System.out.println("输入的字符为:"+i);
        } 

---


