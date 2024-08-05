package main_package;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;
import java.time.LocalDateTime; // Import the LocalDateTime class
import java.time.format.DateTimeFormatter; // Import the DateTimeFormatter class

public class users 
{
	private users generalUser;
	private groups generalGroup;
	private Date date = new Date();
	LocalDateTime myDateObj = LocalDateTime.now();
	DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
	private SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
	private int i;
	private String name;
	private String email;
	private ArrayList<users> userFriends = new ArrayList<>();
	private ArrayList<groups> listOfGroups = new ArrayList<>();
	private ArrayList<posts> listOfUsersPosts = new ArrayList<>();

	public users(String name, String email, connectedClass connector) 
	{	
			this.name = name;
			this.email = email;
			
			connector.writeToList(this);
	}
		


	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}
	
	public void printInfo() {
		System.out.println(this.name + " (" + this.email + ") ");
	}
	

	public boolean checkIfFriend(users checkingUser) {
		for (i=0; i<userFriends.size(); i++) {
			
			users enteredUser = userFriends.get(i);
			String enteredEmail = enteredUser.getEmail();
			String enteredName = enteredUser.getName();
			String checkingEmail = checkingUser.getEmail();
			String checkingName = checkingUser.getName();
			
			if (enteredEmail.equals(checkingEmail) && !checkingName.equals(this.name)) {
				return true;
			}
		}
		
		return false;
	}
	

	public void addFriend(users secondUser) {
		if(!this.checkIfFriend(secondUser)) {
			userFriends.add(secondUser);
			secondUser.setFriend(this);
			//System.out.println(this.name + " and " + secondUser.name + " are now friends!"); 
		}
	}
	

	public void setFriend(users u1) {
		generalUser = u1;
		
		userFriends.add(generalUser);
		
	}
	

	public void areCommonFriendsWith(users secondUser) {
		System.out.println("*************************************");
		System.out.println("Common friends of " + this.name + " and " + secondUser.name);
		System.out.println("*************************************");
		
		for(i=0; i<userFriends.size(); i++) {
			users checkingUser = userFriends.get(i);
			if(checkingUser.checkIfFriend(secondUser)) {
				checkingUser.printInfo(); // ΔΕΝ χρειάζεται Γραφική Διασύνδεση
			}
		}
		
		System.out.println("---------------------------");
	}
	

	public void showFriends() {
		
		System.out.println("************************************** ");
		System.out.println("Friends of " + this.name);
		System.out.println("************************************** ");
		for(users checkingUser : userFriends) {
				checkingUser.printInfo(); // ΔΕΝ χρειάζεται Γραφική Διασύνδεση
		}
		System.out.println("---------------------------");
	}
	

	public String isInfected() {
		ArrayList<users> affected = new ArrayList<>();
		ArrayList<users> singleAffected = new ArrayList<>();
		
		//System.out.println("************************************** ");
		//System.out.println(this.name + " has been infected. The following users have to be tested");
		//System.out.println("************************************** ");
		
		for(users firstUser : userFriends) {
			affected.add(firstUser);
			for (users secondUser : firstUser.userFriends) {
				affected.add(secondUser);
			}
		}
		
		for(users sampleUser : affected) {
			if(!singleAffected.contains(sampleUser) && !sampleUser.equals(this)) {
				singleAffected.add(sampleUser);
			}
		}
		
		String infectionsText = "****************************************************************************" + "\n" +
				this.name + " has been infected. The following users have to be tested" + "\n" +
				"****************************************************************************" + "\n";

		for(users sampleUser : singleAffected) {
			infectionsText += sampleUser.getName();
			infectionsText += "\n";
		}
		//System.out.println("-----------------------------");
		
		return infectionsText;
	}
	
	public void setMembersGroup(groups sampleGroup) {
		generalGroup = sampleGroup;
		listOfGroups.add(sampleGroup);
	}
	
	
	public boolean checkForClosedGroups(groups checkingGroup, connectedClass connector) {
		boolean flag = false;
		for(i=0; i<userFriends.size(); i++) {
			users checkingUser = userFriends.get(i);
			if(this.checkIfFriend(checkingUser) && checkingGroup.checkGroupForMember(checkingUser, connector)) {
				return true;
			}else {
				flag = false;
			}
		}
		
		return flag;
	}
	
	public void showMembersGroups() {
		System.out.println("************************************** ");
		System.out.println("Groups that " + this.name + " has been enrolled in ");
		System.out.println("************************************** ");
		for (groups sampleGroups : listOfGroups) {
			System.out.println(sampleGroups.getName());
		}
		System.out.println("-----------------------------");
	}
	
	public String suggestedFriends() {
		String sugFriendText = "";
		
		for(users firstUser : userFriends) {
			for (users secondUser : firstUser.userFriends) {
				if(!this.getEmail().equals(secondUser.getEmail())
						&& this.checkIfFriend(firstUser) 
						&& !this.checkIfFriend(secondUser)) {
						sugFriendText += secondUser.getName();
						sugFriendText += "\n";
				}
			}
		}
		
		
		return sugFriendText;
	}
	
	public void addANewPost(String getText, connectedClass connector) {
		LocalDateTime myDateObj = LocalDateTime.now();
		DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
		String formattedDate = myDateObj.format(myFormatObj);
		posts newPost = new posts(formattedDate, getText, this.name);
		connector.writeToListOfPosts(newPost);
	}
	
	public String returnMineAndMyFriendsPosts(connectedClass connector) {
		String postsText = "";
		
		for(posts checkingPost : connector.listOfUsersPosts) {
			postsText += checkingPost.getName() + ", " + checkingPost.getTimestamp() + ", " + checkingPost.getPostText() + "\n";
		}
		for(users checkingUser : userFriends) {
			if(this.checkIfFriend(checkingUser)) {
				for(posts checkingPost : checkingUser.listOfUsersPosts) {
					postsText += checkingPost.getName() + ", " + checkingPost.getTimestamp() + ", " + checkingPost.getPostText() + "\n";
				}
			}	
		}
		
		return postsText;
	}
	

	
	public ArrayList<posts> getListOfUsersPosts() {
		return listOfUsersPosts;
	}


	public void setListOfUsersPosts(ArrayList<posts> listOfUsersPosts) {
		this.listOfUsersPosts = listOfUsersPosts;
	}


	
	public ArrayList<groups> getListOfGroups() {
		return listOfGroups;
	}


	public void setListOfGroups(ArrayList<groups> listOfGroups) {
		this.listOfGroups = listOfGroups;
	}
	

	public ArrayList<users> getUserFriends() {
		return userFriends;
	}



	public void setUserFriends(ArrayList<users> userFriends) {
		this.userFriends = userFriends;
	}

	
}	
			