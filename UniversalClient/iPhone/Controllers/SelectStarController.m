//
//  SelectStarController.m
//  UniversalClient
//
//  Created by Kevin Runde on 12/17/10.
//  Copyright 2010 n/a. All rights reserved.
//

#import "SelectStarController.h"
#import "LEMacros.h"
#import "Session.h"
#import "LEViewSectionTab.h"
#import "LETableViewCellButton.h"
#import "LETableViewCellLabeledText.h"
#import "LETableViewCellTextEntry.h"
#import "LEMapSearchStars.h"


typedef enum {
	SECTION_SEARCH,
	SECTION_STARS
} SECTION;


@implementation SelectStarController


@synthesize stars;
@synthesize delegate;
@synthesize nameCell;


#pragma mark -
#pragma mark View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.navigationItem.title = @"Select Star";
	
	self.sectionHeaders = _array([LEViewSectionTab tableView:self.tableView withText:@"Search"], [LEViewSectionTab tableView:self.tableView withText:@"Matches"]);
	
	self.nameCell = [LETableViewCellTextEntry getCellForTableView:self.tableView];
	[self.nameCell setReturnKeyType:UIReturnKeySearch];
	self.nameCell.delegate = self;
	self.nameCell.label.text = @"Star Name";
}


- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	[self.nameCell becomeFirstResponder];
}


#pragma mark -
#pragma mark Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    // Return the number of sections.
    return 2;
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	switch (section) {
		case SECTION_SEARCH:
			return 1;
			break;
		case SECTION_STARS:
			return MAX(1, [self.stars count]);
			break;
		default:
			return 0;
			break;
	}
}


// Customize the appearance of table view cells.
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	switch (indexPath.section) {
		case SECTION_SEARCH:
			return [LETableViewCellTextEntry getHeightForTableView:tableView];
			break;
		case SECTION_STARS:
			if (self.stars && [self.stars count] > 0) {
				return [LETableViewCellLabeledText getHeightForTableView:tableView];
			} else {
				return [LETableViewCellButton getHeightForTableView:tableView];
			}
			break;
		default:
			return 0.0;
			break;
	}
}


// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = nil;
	
	switch (indexPath.section) {
		case SECTION_SEARCH:
			; // DO NOT REMOVE
			cell = self.nameCell;
			break;
		case SECTION_STARS:
			if (self.stars) {
				if ([self.stars count] > 0) {
					NSDictionary *star = [self.stars objectAtIndex:indexPath.row];
					LETableViewCellButton *starButtonCell = [LETableViewCellButton getCellForTableView:tableView];
					starButtonCell.textLabel.text = [star objectForKey:@"name"];
					cell = starButtonCell;
				} else {
					LETableViewCellLabeledText *noMatchesCell = [LETableViewCellLabeledText getCellForTableView:tableView isSelectable:NO];
					noMatchesCell.content.text = @"No Matches";
					cell = noMatchesCell;
				}
				
			} else {
				LETableViewCellLabeledText *searchCell = [LETableViewCellLabeledText getCellForTableView:tableView isSelectable:NO];
				searchCell.content.text = @"Enter a name";
				cell = searchCell;
			}
			break;
		default:
			cell = nil;
			break;
	}
	
	return cell;
}


#pragma mark -
#pragma mark UITableViewDataSource Methods

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	if (indexPath.section == SECTION_STARS) {
		NSDictionary *star = [self.stars objectAtIndex:indexPath.row];
		[delegate selectedStar:star];
	}
	
}


#pragma mark -
#pragma mark Memory management

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Relinquish ownership any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	self.nameCell = nil;
    [super viewDidUnload];
}


- (void)dealloc {
	self.nameCell = nil;
	self.stars = nil;
    [super dealloc];
}


#pragma mark -
#pragma mark Action Methods

- (void)searchForStars:(NSString *)starName {
	[[[LEMapSearchStars alloc] initWithCallback:@selector(starsFound:) target:self name:starName] autorelease];
}


#pragma mark -
#pragma mark Callback Methods

- (void)starsFound:(LEMapSearchStars *)request {
	self.stars = request.stars;
	[self.tableView reloadData];
}


#pragma mark -
#pragma mark UITextFieldDelegate methods

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
	if ([textField.text length] > 2) {
		[self searchForStars:textField.text];
		return YES;
	} else {
		UIAlertView *av = [[[UIAlertView alloc] initWithTitle:@"Error" message:@"You must enter at least 3 characters to search." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] autorelease];
		[av show];
		return NO;
	}
}


#pragma mark -
#pragma mark Class Methods

+ (SelectStarController *)create {
	return [[[SelectStarController alloc] init] autorelease];
}


@end
