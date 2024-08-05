package gui;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

import main_package.connectedClass;
import main_package.groups;
import main_package.users;

public class user_page extends JFrame 
{
	private JFrame userPage = new JFrame();
	private JPanel firstPanel = new JPanel();
	private JPanel eastPanel = new JPanel();
	private JPanel westPanel = new JPanel();
	private JPanel endPanel = new JPanel();
	private JLabel userName = new JLabel("user name");
	private JLabel userEmail = new JLabel("user email");
	private JTextField addFriend = new JTextField("add friend");
	private JTextField subToGroup = new JTextField("subscribe to group");
	private JTextArea newPostField = new JTextArea(10, 10);
	private JTextArea postsOfFriends = new JTextArea(10,10);
	private JLabel firstLabel = new JLabel("Recent Posts by Friends");
	private JLabel secondLabel = new JLabel("Suggested Friends");
	private JTextArea suggestedFriends = new JTextArea(5,5);
	private JButton subToGroupButton = new JButton ("Subscribe");
	private JButton addFriendButton = new JButton("Add Friend");
	private JButton postButton = new JButton("Post");
	private JButton backToLogin = new JButton("Back To Login Screen");
	
	public user_page(JFrame mainMenu, String name, String email, connectedClass connector) 
	{
		
		for(users aUser : connector.getUsersOfTheApp()) {
			if(aUser.getEmail().equals(email)){
				postsOfFriends.setText(aUser.returnMineAndMyFriendsPosts(connector));
			}
		}
		
		for(users aUser : connector.getUsersOfTheApp()) {
			if(aUser.getEmail().equals(email)) {
				suggestedFriends.setText(aUser.suggestedFriends());
			}
		}
		
		backToLogin.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				mainMenu.setVisible(true);
				userPage.dispose();
			}
			
		});
		
		addFriendButton.addActionListener(new ActionListener() {

			users firstUser;
			users secondUser;
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				for(users aSampleUser : connector.getUsersOfTheApp()) {
					if(aSampleUser.getEmail().equals(email)) {
						firstUser = aSampleUser;
					}
				}
				
				for(users aSecondSampleUser : connector.getUsersOfTheApp()) {
					if(aSecondSampleUser.getName().equals(addFriend.getText())) {
						secondUser = aSecondSampleUser;
					}
				}
				
				if(!(secondUser == null)) {
					if(!firstUser.checkIfFriend(secondUser)) {
						firstUser.addFriend(secondUser);
						JOptionPane.showMessageDialog(userPage, firstUser.getName() + " is now friend with " + secondUser.getName());
					}else {
						JOptionPane.showMessageDialog(userPage, "Users are already Friends");
					}
	
					
					for(users aUser : connector.getUsersOfTheApp()) {
						if(aUser.getEmail().equals(email)) {
							suggestedFriends.setText(aUser.suggestedFriends());
						}
					}
				}else {
					JOptionPane.showMessageDialog(userPage, "There isn't any user named like that.");
				}
			}
		});
		
		subToGroupButton.addActionListener(new ActionListener() {
			
			users firstUser;
			String nameOfGroup;
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				for(users aSampleUser : connector.getUsersOfTheApp()) {
					if(aSampleUser.getEmail().equals(email)) {
						firstUser = aSampleUser;
					}
				}
				
				nameOfGroup = subToGroup.getText();
				for(groups aGroup : connector.getListOfGroups()) {
					if(aGroup.getName().equals(nameOfGroup)) {
						if(!aGroup.checkGroupForMember(firstUser, connector) && !firstUser.checkForClosedGroups(aGroup, connector)) {
							aGroup.inGroupAddMember(firstUser, connector);
							JOptionPane.showMessageDialog(userPage, firstUser.getName() + " has been enrolled in " + nameOfGroup);
							break;
						}else {
							JOptionPane.showMessageDialog(userPage, firstUser.getName() + " has already been enrolled in " + nameOfGroup);
							break;
						}
					}else {
						JOptionPane.showMessageDialog(userPage, "This group doesn't exist.");
						break;
					}
				}
			}
			
		});
		
		postButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				for(users aUser : connector.getUsersOfTheApp()) {
					if(aUser.getEmail().equals(email)){
						aUser.addANewPost(newPostField.getText(), connector);
						JOptionPane.showMessageDialog(userPage, "A new post has been made.");
						newPostField.setText("");
						postsOfFriends.setText(aUser.returnMineAndMyFriendsPosts(connector));
					}
				}
				
			}
		
		});
		
		userName.setText(name);
		userEmail.setText(email);
		
		firstPanel.add(userName);
		firstPanel.add(userEmail);
		firstPanel.add(backToLogin);
		firstPanel.add(addFriend);
		firstPanel.add(addFriendButton);
		firstPanel.add(subToGroup);
		firstPanel.add(subToGroupButton);
		userPage.add(firstPanel, BorderLayout.PAGE_START);
		
		eastPanel.add(newPostField);
		eastPanel.add(postButton);
		userPage.add(eastPanel, BorderLayout.EAST);
		
		westPanel.add(firstLabel);
		westPanel.add(postsOfFriends);
		userPage.add(westPanel, BorderLayout.WEST);
		
		endPanel.add(secondLabel);
		endPanel.add(suggestedFriends);
		userPage.add(endPanel, BorderLayout.PAGE_END);
		
		userPage.pack();
		userPage.setVisible(true);
		userPage.setLocationRelativeTo(null);
		userPage.setTitle("Σελίδα Χρήστη");
		userPage.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
