import javax.swing.JOptionPane;

public class MOMO {

    public static void main(String[] args) {
        final String MTN_USSD_CODE = "*170#";
        final int MOMO_PIN = 1234;

        String userUSSDCode = JOptionPane.showInputDialog("Enter the MOMO code\nUSSD:");

        while (!userUSSDCode.equals(MTN_USSD_CODE)) {
            JOptionPane.showMessageDialog(null, "Incorrect code! Try again.");
            userUSSDCode = JOptionPane.showInputDialog("Enter the MOMO code\nUSSD:");
        }

        String[] options = {"Transfer Money", "MomoPay", "Airtime/Bundle", "Exit"};
        int choice = JOptionPane.showOptionDialog(null, "MTN MOMO", "Menu",
                JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, options, options[0]);

        switch (choice) {
            case 0:
                handleTransferMoney(MOMO_PIN);
                break;

            case 1:
                JOptionPane.showMessageDialog(null, "MomoPay");
                break;

            case 2:
                handleAirtimeBundle(MOMO_PIN);
                break;

            case 3:
                JOptionPane.showMessageDialog(null, "Thanks for transacting with us!!!");
                System.exit(0);
                break;

            default:
                JOptionPane.showMessageDialog(null, "Options are 1 - 4");
                break;
        }
    }

    private static void handleTransferMoney(int momoPIN) {
        String[] transferOptions = {"Momo User", "Other Networks"};
        int choice = JOptionPane.showOptionDialog(null, "Transfer Money", "Menu",
                JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, transferOptions, transferOptions[0]);

        if (choice == 0) {
            String recipientNumber1 = JOptionPane.showInputDialog("Enter Mobile Number");
            String recipientNumber2 = JOptionPane.showInputDialog("Confirm Mobile Number");

            if (recipientNumber1.equals(recipientNumber2)) {
                float amount = Float.parseFloat(JOptionPane.showInputDialog("Enter the Amount\nAmount:"));
                String reference = JOptionPane.showInputDialog("Enter your Reference\n->");

                int enteredPIN = Integer.parseInt(JOptionPane.showInputDialog("Transfer to " + recipientNumber1 +
                        ", an Amount of " + amount + " with reference: " + reference +
                        ". Fee is GHS 0.00, Tax GHS 0.00, total amount is " + amount +
                        "\nEnter Momo Pin OR any key to cancel"));

                if (enteredPIN == momoPIN) {
                    JOptionPane.showMessageDialog(null, "You sent " + amount + " to " + recipientNumber1);
                } else {
                    JOptionPane.showMessageDialog(null, "Wrong Pin");
                }

            } else {
                JOptionPane.showMessageDialog(null, "Incorrect Number! Try again");
            }

        } else if (choice == 1) {
            String[] otherNetworks = {"Telecel", "AirtelTigo", "E-switch", "Zeepay"};
            JOptionPane.showOptionDialog(null, "Transfer Money to Other Networks", "Menu",
                    JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, otherNetworks, otherNetworks[0]);
        } else {
            JOptionPane.showMessageDialog(null, "Invalid Option! (1-2)");
        }
    }

    private static void handleAirtimeBundle(int momoPIN) {
        String[] airtimeOptions = {"Airtime", "Internet Bundles", "Fixed Broadband", "Schedule Airtime", "Just4U"};
        int airtimeChoice = JOptionPane.showOptionDialog(null, "Airtime/Bundle", "Menu",
                JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, airtimeOptions, airtimeOptions[0]);

        if (airtimeChoice == 0) {
            String[] airtimeSelfOptions = {"Self", "Others"};
            int airtimeSelf = JOptionPane.showOptionDialog(null, "Airtime", "Menu",
                    JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, airtimeSelfOptions, airtimeSelfOptions[0]);

            if (airtimeSelf == 0) {
                float amount = Float.parseFloat(JOptionPane.showInputDialog("Enter the amount of airtime to buy:"));
                String recipientName = JOptionPane.showInputDialog("Enter your name:");

                int enteredPIN = Integer.parseInt(JOptionPane.showInputDialog("DEAR " + recipientName +
                        ", Send GHS " + amount + " Airtime to self. Fee is GHS 0.00." +
                        "\nEnter Momo Pin OR any key to cancel"));

                if (enteredPIN == momoPIN) {
                    JOptionPane.showMessageDialog(null, "You sent " + amount + " to yourself");
                } else {
                    JOptionPane.showMessageDialog(null, "Wrong Pin");
                }

            } else if (airtimeSelf == 1) {
                String recipientNumber1 = JOptionPane.showInputDialog("Enter Mobile Number");
                String recipientNumber2 = JOptionPane.showInputDialog("Confirm Mobile Number");

                if (recipientNumber1.equals(recipientNumber2)) {
                    float amount = Float.parseFloat(JOptionPane.showInputDialog("Enter the Amount\nAmount:"));
                    String reference = JOptionPane.showInputDialog("Enter your Reference\n->");

                    int enteredPIN = Integer.parseInt(JOptionPane.showInputDialog("Send GHS " + amount + " to " + recipientNumber1 +
                            ". Fee is GHS 0.00." + "\nEnter Momo Pin OR any key to cancel"));

                    if (enteredPIN == momoPIN) {
                        JOptionPane.showMessageDialog(null, "You sent " + amount + " to " + recipientNumber1);
                    } else {
                        JOptionPane.showMessageDialog(null, "Wrong Pin");
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "Incorrect Number! Try again");
                }
            }
        }
    }
}
