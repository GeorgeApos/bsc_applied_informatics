package gui;

import java.awt.BorderLayout;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.*;

import main_package.*;

public class main_menu extends JFrame 
{
	private JFrame mainMenu = new JFrame();
	private JPanel newUserPanel = new JPanel();
	private JPanel centerPanel = new JPanel();
	private JPanel endPanel = new JPanel();
	private JButton newUser = new JButton("New User");
	private JButton enterUserPage = new JButton("Enter User Page");
	private JButton showInf = new JButton("Show Potential Infections");
	private JButton savePamak = new JButton("Save Pamakbook");
	private JTextField userName = new JTextField("user name");
	private JTextField userEmail = new JTextField("user email");
	

	public main_menu() {
		
		connectedClass connector = new connectedClass();
		
		users u1 = new users("Makis", "iis1998@uom.edu.gr", connector);
		users u2 = new users("Petros", "ics1924@uom.edu.gr", connector);
		users u3 = new users("Maria", "iis2012@uom.edu.gr", connector);
		users u4 = new users("Gianna", "iis19133@uom.edu.gr", connector);
		users u5 = new users("Nikos", "dai1758@uom.edu.gr", connector);
		users u6 = new users("Babis", "ics19104@uom.edu.gr", connector);
		users u7 = new users("Stella", "dai1827@uom.edu.gr", connector);
		
		groups g1 = new groups("WebGurus","A group for web passionates", connector);
		closedGroups g2 = new closedGroups("ExamSolutions","Solutions to common exam questions", connector); 

		
		newUser.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				
				String name = userName.getText();
				String email = userEmail.getText();
				
				if(connector.checkIfUnique(name, email)) {
					if(email.startsWith("iis")
							||email.startsWith("dai")
							||email.startsWith("ics")
							&&email.endsWith("@uom.edu.gr")){
						new users(name, email, connector);
						JOptionPane.showMessageDialog(mainMenu, "User " + name + " has been created!");
					}else {
						JOptionPane.showMessageDialog(mainMenu, "User " + name + " has not been created. Email format is not acceptable.");
					}
				}else {
					JOptionPane.showMessageDialog(mainMenu, "User " + name + " already exists!");
				}
			}
		});

		
		showInf.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(!connector.checkIfUnique(userName.getText(), userEmail.getText())) {	
					infections_page infPage = new infections_page(mainMenu,userEmail.getText(), connector);
					mainMenu.dispose();
				}else {
					JOptionPane.showMessageDialog(mainMenu, "User " + userName.getText() + " does not exist!");
				}
			}
		});
		
		enterUserPage.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(!connector.checkIfUnique(userName.getText(), userEmail.getText())) {	
						user_page userPage = new user_page(mainMenu, userName.getText(), userEmail.getText(), connector);
						mainMenu.dispose();
				}else {
					JOptionPane.showMessageDialog(mainMenu, "User " + userName.getText() + " does not exist!");
				}
			}
			
		});
		
		savePamak.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(mainMenu, "PamakBook version iis20001 does not support this feature.");
			}
			
		});
		
		newUserPanel.add(newUser);
		newUserPanel.add(userName);
		newUserPanel.add(userEmail);
		mainMenu.add(newUserPanel, BorderLayout.PAGE_START);
		
		centerPanel.add(enterUserPage);
		centerPanel.add(showInf);
		mainMenu.add(centerPanel, BorderLayout.CENTER);
	
		endPanel.add(savePamak);
		mainMenu.add(endPanel, BorderLayout.PAGE_END);
		 
		mainMenu.pack();
		mainMenu.setVisible(true);
		mainMenu.setLocationRelativeTo(null);
		mainMenu.setTitle("Κεντρική Σελίδα");
		mainMenu.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	
}
