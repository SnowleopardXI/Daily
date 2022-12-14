//notepad with midi player
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.*;
import javax.swing.*;
import javax.sound.midi.*;

public class notepad extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    private static final int WIDTH = 300;
    private static final int HEIGHT = 200;
    private static final String TITLE = "Notepad with Midi Player";
    private static final String Midi_CHOOSER_TITLE = "Select a MIDI file";
    private static final String FILE_CHOOSER_TITLE = "Select a text file";
    private static final String PLAY_BUTTON_TEXT = "Play";
    private static final String STOP_BUTTON_TEXT = "Stop";
    private static final String ABOUT_BUTTON_TEXT = "About";
    private static final String OPEN_TEXT = "Open text file";
    private static final String OPEN_MIDI_TEXT = "Open midi file";
    private static final String EXIT_TEXT = "Exit";
    private static final String SAVE_TEXT = "Save";
    private static final String ABOUT_TEXT = "Notepad v1.0";
    @SuppressWarnings("deprecation")
    public static void main(String[] args) {
        notepad mp = new notepad();
        mp.show();
    }
    //Menu
    private JMenuBar menuBar;
    private JMenu fileMenu;
    private JMenu midiMenu;
    private JMenuItem openMenuItem;
    private JMenuItem openMidiMenuItem;
    private JMenuItem exitMenuItem;
    private JMenuItem saveMenuItem;
    //Buttons
    private JButton playButton;
    private JButton stopButton;
    private JButton aboutButton;
    //File chooser
    private JFileChooser fileChooser;
    //Midi player
    private Sequencer sequencer;
    private Sequence sequence;
    private File file;
    //Text area
    private JTextArea textArea;
    public notepad() {
        super(TITLE);
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Menu
        menuBar = new JMenuBar();
        fileMenu = new JMenu("File");
        midiMenu = new JMenu("Midi");
        openMenuItem = new JMenuItem(OPEN_TEXT);
        openMidiMenuItem = new JMenuItem(OPEN_MIDI_TEXT);
        exitMenuItem = new JMenuItem(EXIT_TEXT);
        saveMenuItem = new JMenuItem(SAVE_TEXT);
        fileMenu.add(openMenuItem);
        fileMenu.add(saveMenuItem);
        fileMenu.add(exitMenuItem);
        midiMenu.add(openMidiMenuItem);
        menuBar.add(fileMenu);
        menuBar.add(midiMenu);
        setJMenuBar(menuBar);
        //Buttons
        playButton = new JButton(PLAY_BUTTON_TEXT);
        stopButton = new JButton(STOP_BUTTON_TEXT);
        aboutButton = new JButton(ABOUT_BUTTON_TEXT);
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(playButton);
        buttonPanel.add(stopButton);
        buttonPanel.add(aboutButton);
        //Text area
        textArea = new JTextArea();
        JScrollPane scrollPane = new JScrollPane(textArea);
        //Add components
        Container contentPane = getContentPane();
        contentPane.add(buttonPanel, BorderLayout.NORTH);
        contentPane.add(scrollPane, BorderLayout.CENTER);
        //File chooser
        fileChooser = new JFileChooser();
        //Midi player
        try {
            sequencer = MidiSystem.getSequencer();
            sequencer.open();
        } catch (MidiUnavailableException e) {
            e.printStackTrace();
        }
        //Add listeners
        openMenuItem.addActionListener(this);
        openMidiMenuItem.addActionListener(this);
        exitMenuItem.addActionListener(this);
        saveMenuItem.addActionListener(this);
        playButton.addActionListener(this);
        stopButton.addActionListener(this);
        aboutButton.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == openMenuItem) {
            openFile();
        } else if (e.getSource() == openMidiMenuItem) {
            openMidiFile();
        } else if (e.getSource() == exitMenuItem) {
            System.exit(0);
        } else if (e.getSource() == saveMenuItem) {
            saveFile();
        } else if (e.getSource() == playButton) {
            play();
        } else if (e.getSource() == stopButton) {
            stop();
        } else if (e.getSource() == aboutButton) {
            JOptionPane.showMessageDialog(this, ABOUT_TEXT);
        }
    }
    private void openFile() {
        int returnVal = fileChooser.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            file = fileChooser.getSelectedFile();
            try {
                BufferedReader in = new BufferedReader(new FileReader(file));
                String line;
                while ((line = in.readLine()) != null) {
                    textArea.append(line + "\r");
                }
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    private void openMidiFile() {
        int returnVal = fileChooser.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            file = fileChooser.getSelectedFile();
            try {
                sequence = MidiSystem.getSequence(file);
                sequencer.setSequence(sequence);
            } catch (InvalidMidiDataException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    private void saveFile() {
        int returnVal = fileChooser.showSaveDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            file = fileChooser.getSelectedFile();
            try {
                BufferedWriter out = new BufferedWriter(new FileWriter(file));
                out.write(textArea.getText());
                out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    private void play() {
        sequencer.start();
    }
    private void stop() {
        sequencer.stop();
    }
}
