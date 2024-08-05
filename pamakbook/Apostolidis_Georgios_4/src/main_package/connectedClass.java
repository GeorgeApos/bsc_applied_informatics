package main_package;

import java.util.ArrayList;

public class connectedClass {
	
	ArrayList<users> usersOfTheApp;
	ArrayList<groups> listOfGroups;
	ArrayList<posts> listOfUsersPosts;
	ArrayList<users> listOfMembersInGroups;
	
	
	public connectedClass() {
		usersOfTheApp = new ArrayList<>();
		listOfGroups = new ArrayList<>();
		listOfUsersPosts = new ArrayList<>();
		listOfMembersInGroups = new ArrayList<>();
		
	}
	

	public boolean checkIfUnique(String name, String email) {
		
		for(users checkingUser : usersOfTheApp) {
			if(checkingUser.getEmail().equals(email) && checkingUser.getName().equals(name)) {
				return false;
			}
		}
		
		return true;
	}
	
	public void writeToList(users aUser) {
		usersOfTheApp.add(aUser);
	}
	
	public void writeToListGroup(groups aGroup) {
		listOfGroups.add(aGroup);
	}
	
	public void writeToListOfPosts(posts newPost) {
		listOfUsersPosts.add(newPost);
	}
	
	public void writeMemberToGroup(users aUser) {
		listOfMembersInGroups.add(aUser);
	}

	public ArrayList<users> getUsersOfTheApp() {
		return usersOfTheApp;
	}

	public ArrayList<groups> getListOfGroups() {
		return listOfGroups;
	}

	public ArrayList<users> getListOfMembersInGroups() {
		return listOfMembersInGroups;
	}

	public void setListOfMembersInGroups(ArrayList<users> listOfMembersInGroups) {
		this.listOfMembersInGroups = listOfMembersInGroups;
	}

}
