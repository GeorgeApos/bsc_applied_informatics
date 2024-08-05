package main_package;

import java.util.*;

public class posts {
	
	String timestamp;
	String postText;
	String name;
	
	public posts(String timestamp, String postText, String name) {
		this.timestamp = timestamp;
		this.postText = postText;
		this.name = name;
	}

	public String getTimestamp() {
		return timestamp;
	}

	public void setTimestamp(String timestamp) {
		this.timestamp = timestamp;
	}

	public String getPostText() {
		return postText;
	}

	public void setPostText(String postText) {
		this.postText = postText;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	
}
