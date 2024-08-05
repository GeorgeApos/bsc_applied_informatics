package main_package;

import java.util.*;

public class groups {
	
	int i;
	private String name;
	private String description;
	private ArrayList<users> listOfMembersInGroups = new ArrayList<>();
	
	public groups(String name, String description, connectedClass connector) {
		this.name = name;
		this.description = description;
		
		connector.writeToListGroup(this);
	}

	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	
	/*
	 * 
	 */
	public boolean checkGroupForMember(users sampleUser, connectedClass connector) {
		for(users checkingUser : connector.getListOfMembersInGroups()){
			if(sampleUser.getName().equals(checkingUser.getName()) 
					&& sampleUser.getEmail().equals(checkingUser.getEmail())
					) {
				return true;
			}
		}
		return false;
	}
	
	/*
	 * 
	 */
	public void inGroupAddMember(users sampleUser, connectedClass connector) {
		if(!this.checkGroupForMember(sampleUser, connector)) {
			connector.writeMemberToGroup(sampleUser);
			sampleUser.setMembersGroup(this);
			//System.out.println(sampleUser.getName() + " has been successfully enrolled in group " + this.name);
			
		}
	}
	
	/*
	 * 
	 */
	public void showMembersInGroup() {
		System.out.println("************************************** ");
		System.out.println("Members of group " + this.name);
		System.out.println("************************************** ");
		for (users sampleUser : getListOfMembersInGroups()) {
			sampleUser.printInfo();
		}
		System.out.println("-----------------------------");
	}

	public ArrayList<users> getListOfMembersInGroups() {
		return listOfMembersInGroups;
	}

	public void setListOfMembersInGroups(ArrayList<users> listOfMembersInGroups) {
		this.listOfMembersInGroups = listOfMembersInGroups;
	}

}
