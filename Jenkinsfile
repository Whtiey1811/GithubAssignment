pipeline {
    agent any
    environment {
        // Use a single credential ID for both username and password
        NEXUS_CREDS = credentials('nexus-creds')  // Replace with your credentials ID for Nexus
        NEXUS_URL = 'http://localhost:8081/repository/cpp-artifacts/'  // URL for Nexus repository
    }
    stages {
        stage('Checkout') {
            steps {
                echo "Checking out the repository"
                git 'https://github.com/Whtiey1811/GithubAssignment'
                sh 'echo "This is the Checkout stage!"'  // Debugging step
            }
        }
        stage('Build') {
            steps {
                echo "Building the project using 'make'"
                sh 'echo "This is the Build stage!"'  // Debugging step
                bat 'make'  // Adjust this to your build process
            }
        }
        stage('Test') {
            steps {
                echo "Running tests..."
                // Optional: Add testing steps here (C++ testing framework)
            }
        }
        stage('Upload to Nexus') {
            steps {
                script {
                    echo "Attempting to upload the executable to Nexus..."
                    // Check if the file exists before uploading
                    if (fileExists('target/myprogram.exe')) {
                        def nexusUsername = NEXUS_CREDS_USR
                        def nexusPassword = NEXUS_CREDS_PSW

                        // Upload the built executable to Nexus repository with verbose output
                        sh """
                            curl -v -u ${nexusUsername}:${nexusPassword} --upload-file target/myprogram.exe \
                                ${NEXUS_URL}/myprogram.exe
                        """
                    } else {
                        error "The file target/myprogram.exe does not exist!"
                    }
                }
            }
        }
    }
    post {
        always {
            echo 'Pipeline has finished running'
        }
        success {
            echo 'Build and upload successful'
        }
        failure {
            echo 'Build or upload failed'
        }
    }
}
